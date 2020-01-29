/*
 * CDCEmulator.c
 *
 *  Created on: Feb 10, 2019
 *      Author: lengyela
 */


/* -- Includes ----------------------------------------------------------------------- */
#include <CDCEmulator.h>
#include <CDCEMessage.h>


/* -- Defines ------------------------------------------------------------------------ */
#define CDCE_STATE__NONE            0x00u
#define CDCE_STATE__NOT_CONFIGURED  0x01u
#define CDCE_STATE__CONFIGURED      0x02u
#define CDCE_STATE__BOOTING         0x03u
#define CDCE_STATE__STANDBY         0x04u
#define CDCE_STATE__PLAYING         0x05u
#define CDCE_STATE__ERROR           0x06u

#define CDCE_TIMEOUT__SEND                      500u
#define CDCE_TIMEOUT__RECEIVE_ACK               50u
#define CDCE_TIMEOUT__RECEIVE_MESSAGE           2000u
#define CDCE_TIMEOUT__RECEIVE_MESSAGE_FRAGMENT  100u
#define CDCE_TIMEOUT__PERIODIC                  1000u

#define CDCE_MAX_FAST_RETRY__SEND       0x03u
#define CDCE_MAX_PERIODIC_RETRY__SEND   0x03u


/* -- Typedefs ----------------------------------------------------------------------- */
typedef uint8_t	CDCE_State;

typedef uint32_t CDCE_Timeout;


/* -- Variables ---------------------------------------------------------------------- */
static CDCEM_Message txMessage;
static CDCEM_Message rxMessage;

static CDCEM_FrameId txFrameId;

static CDCE_State previousState	= CDCE_STATE__NONE;
static CDCE_State currentState  = CDCE_STATE__NOT_CONFIGURED;
static CDCE_State nextState     = CDCE_STATE__NONE;
static volatile CDCE_Config config;


/* -- Prototypes --------------------------------------------------------------------- */
static bool sendMessage(void);
static bool receiveMessage(CDCE_Timeout *timeout);
static bool waitingForMessage(const CDCEM_PayloadType payloadType, CDCE_Timeout*);
static void doBooting(void);
static void doStandby(void);
static void doPlaying(void);
static void onEnter(CDCE_State state);
static void onExit(CDCE_State state);
static void onExecuteTransitionAction(CDCE_State from, CDCE_State to);
static void changeState(CDCE_State state);


/* -- Functions ---------------------------------------------------------------------- */
static bool sendMessage(void)
{
	HAL_StatusTypeDef   status          = HAL_ERROR;
	CDCEM_Rc            cdcemRc         = CDCEM_RC__OK;
	CDCEM_MessageLength messageLength   = 0u;


	cdcemRc = CDCEM_getMessageLength(txMessage, &messageLength);
    if (CDCEM_RC__OK != cdcemRc)
    {
        return false;
    }

    uint8_t periodicRetryCntr = 0u;
    while ((periodicRetryCntr < CDCE_MAX_PERIODIC_RETRY__SEND)
            && (HAL_OK != status))
    {
        periodicRetryCntr++;

        if (1 < periodicRetryCntr)
        {
            cdcemRc = CDCEM_RC__OK;

            cdcemRc |= CDCEM_setFrameId(txMessage, ++txFrameId);
            cdcemRc |= CDCEM_refreshCRC(txMessage);
            if (CDCEM_RC__OK != cdcemRc)
            {
                return false;
            }

            HAL_Delay(CDCE_TIMEOUT__PERIODIC);
        }

        uint8_t fastRetryCntr = 0u;
        while ((fastRetryCntr < CDCE_MAX_FAST_RETRY__SEND) && (HAL_OK != status))
        {
            fastRetryCntr++;

            status = HAL_UART_Transmit(config.huart, &txMessage[0],
                    messageLength, CDCE_TIMEOUT__SEND);
            if (HAL_OK != status)
            {
                continue;
            }

            status = HAL_UART_Receive(config.huart, rxMessage, 1u,
                    CDCE_TIMEOUT__RECEIVE_ACK);
            if (!CDCEM_isACK(rxMessage))
            {
                status = HAL_ERROR;
            }
        }
    }

    if (HAL_OK == status)
    {
        CDCEM_clearMessage(rxMessage);

        return true;
    }

    return false;
}

static bool receiveMessage(CDCE_Timeout *timeout)
{
	bool                result  = true;
	uint32_t            startTS = 0u;
	uint32_t            endTS   = 0u;
	CDCEM_Rc            cdcemRc = CDCEM_RC__OK;
	HAL_StatusTypeDef   status  = HAL_ERROR;


	startTS = HAL_GetTick();

    for (bool runOnce = true; true == runOnce; runOnce = false)
    {
        status = HAL_UART_Receive(config.huart, &rxMessage[0], 1u, *timeout);
        if ((HAL_OK != status) || !CDCEM_isFrame(rxMessage))
        {
            result = false;
            break;
        }

        status = HAL_UART_Receive(config.huart, &rxMessage[1], 2u,
                CDCE_TIMEOUT__RECEIVE_MESSAGE_FRAGMENT);
        if (HAL_OK != status)
        {
            result = false;
            break;
        }

        status = HAL_UART_Receive(config.huart, &rxMessage[3],
                rxMessage[CDCEM_IDX__DATA_LEN] + 1u,
                CDCE_TIMEOUT__RECEIVE_MESSAGE_FRAGMENT);
        if ((HAL_OK != status) || !CDCEM_isValidHUMessage(rxMessage))
        {
            result = false;
            break;
        }

        cdcemRc = CDCEM_createAck(txMessage);
        if (CDCEM_RC__OK != cdcemRc)
        {
            result = false;
            break;
        }

        status = HAL_UART_Transmit(config.huart, txMessage, 1u,
                CDCE_TIMEOUT__SEND);
        if (HAL_OK != status)
        {
            result = false;
            break;
        }
    }

    endTS = HAL_GetTick();

    uint32_t elapsedTime = 0u;
    if (endTS >= startTS)
    {
        elapsedTime = endTS - startTS;
    }
    else
    {
        elapsedTime = UINT32_MAX - startTS + endTS;
    }

    if (elapsedTime < *timeout)
    {
        *timeout -= elapsedTime;
    }
    else
    {
        *timeout = 0u;
    }

    return result;
}

static bool waitingForMessage(const CDCEM_PayloadType payloadType,
        CDCE_Timeout *timeout)
{
    if (!receiveMessage(timeout)
            || (payloadType != rxMessage[CDCEM_IDX__PAYLOAD_TYPE]))
    {
        return false;
    }

    return true;
}

static void doBooting(void)
{
	CDCEM_Rc cdcemRc;


	/* Send BOOTING */
    txFrameId = 0u;
    cdcemRc = CDCEM_createFrame(txMessage, txFrameId,
            CDCEM_PAYLOAD_TYPE__BOOTING, 0x60u, 0x06u);
    if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    /* Send BOOT_OK */
    cdcemRc = CDCEM_createFrame(txMessage, ++txFrameId,
            CDCEM_PAYLOAD_TYPE__BOOT_OK, 0x00, 0x25u);
    if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    /* Send TRAY_STATUS */
    cdcemRc = CDCEM_createFrame(txMessage, ++txFrameId,
            CDCEM_PAYLOAD_TYPE__TRAY_STATUS, 0x05u, 0x01u, 0xFCu, 0xFCu);
    if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    /* Send RANDOM_STATUS */
    cdcemRc = CDCEM_createFrame(txMessage, ++txFrameId,
            CDCEM_PAYLOAD_TYPE__SET_RANDOM, 0x03u);
    if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    /* Send STATUS */
    cdcemRc = CDCEM_createFrame(txMessage, ++txFrameId,
            CDCEM_PAYLOAD_TYPE__STATUS, 0x01u, 0x03u, 0x09u, 0x05u, 0x01u);
    if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    /* Waiting for HU_ON message */
    CDCE_Timeout timeout = CDCE_TIMEOUT__RECEIVE_MESSAGE;
    if (!waitingForMessage(CDCEM_PAYLOAD_TYPE__HU_ON, &timeout))
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    nextState = CDCE_STATE__STANDBY;
}

static void doStandby(void)
{
	CDCEM_Rc cdcemRc;


	cdcemRc = CDCEM_createFrame(txMessage, ++txFrameId,
            CDCEM_PAYLOAD_TYPE__STATUS, 0x01u, 0x03u, 0x09u, 0x05u, 0x01u);
    if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    CDCE_Timeout timeout = CDCE_TIMEOUT__PERIODIC;
    if (receiveMessage(&timeout))
    {
        switch (rxMessage[CDCEM_IDX__PAYLOAD_TYPE])
        {
        case CDCEM_PAYLOAD_TYPE__REQ_CD_INFO:
            cdcemRc = CDCEM_createFrame(txMessage, ++txFrameId,
                    CDCEM_PAYLOAD_TYPE__CD_SUMMARY, 0x0Fu, 0x01u, 0x00u, 0x00u,
                    0x00u, 0x00u);
            if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
            {
                nextState = CDCE_STATE__ERROR;

                return;
            }

            //TODO timeout shall be less...
            timeout = CDCE_TIMEOUT__PERIODIC;
            if (receiveMessage(&timeout)
                    && (CDCEM_PAYLOAD_TYPE__START_PLAY
                            == rxMessage[CDCEM_IDX__PAYLOAD_TYPE]))
            {
                nextState = CDCE_STATE__PLAYING;

                return;
            }

            break;

        case CDCEM_PAYLOAD_TYPE__START_PLAY:
            nextState = CDCE_STATE__PLAYING;

            return;
        }
    }

    nextState = CDCE_STATE__STANDBY;

    HAL_Delay(timeout);
}

static void doPlaying(void)
{
	CDCEM_Rc cdcemRc;

    cdcemRc = CDCEM_createFrame(txMessage, ++txFrameId,
            CDCEM_PAYLOAD_TYPE__PLAYING, 0x01u, 0x01u, 0x00u, 0x00u, 0x00u,
            0x00u, 0x00u, 0x00u, 0x00u, 0x00u);
    if ((CDCEM_RC__OK != cdcemRc) || !sendMessage())
    {
        nextState = CDCE_STATE__ERROR;

        return;
    }

    CDCE_Timeout timeout = CDCE_TIMEOUT__PERIODIC;
    if (receiveMessage(&timeout))
    {
        switch (rxMessage[CDCEM_IDX__PAYLOAD_TYPE])
        {
        case CDCEM_PAYLOAD_TYPE__STOP_PLAY:
        case CDCEM_PAYLOAD_TYPE__PAUSE:
            nextState = CDCE_STATE__STANDBY;

            return;
        }
    }

    HAL_Delay(timeout);

    nextState = CDCE_STATE__PLAYING;
}


static void onEnter(CDCE_State state)
{
	previousState   = currentState;
	currentState    = state;
	nextState       = CDCE_STATE__NONE;

    switch (state)
    {
    case CDCE_STATE__NOT_CONFIGURED:
    case CDCE_STATE__CONFIGURED:
        // Nothing to do in these cases.

        break;

    case CDCE_STATE__BOOTING:
        doBooting();

        break;

    case CDCE_STATE__STANDBY:
        doStandby();

        break;

    case CDCE_STATE__PLAYING:
        doPlaying();

        break;
    }
}

static void onExit(CDCE_State state)
{
    // TODO: implement if necessary
}

static void onExecuteTransitionAction(CDCE_State from, CDCE_State to)
{
    // TODO: implement if necessary
}

static void changeState(CDCE_State state)
{
    onExit(currentState);

    onExecuteTransitionAction(currentState, state);

    onEnter(state);
}


CDCE_Rc CDCE_configure(CDCE_Config cfg)
{
    if ((CDCE_STATE__NOT_CONFIGURED != currentState)
            && (CDCE_STATE__CONFIGURED != currentState))
    {
        return CDCE_RC__E_CONFIGURING_NOT_ALLOWED;
    }

    if (NULL == cfg.huart)
    {
        currentState = CDCE_STATE__NOT_CONFIGURED;

        return CDCE_RC__E_INVALID_UART_HANDLE;
    }

    //TODO event-handling not supported yet
//	if (NULL == config.eventHandler)
//	{
//		CDCE_goTo(CDCE_STATE__NOT_CONFIGURED);
//
//		return CDCE_RC__INVALID_EVENT_HANDLER;
//	}

    config = cfg;

    currentState = CDCE_STATE__CONFIGURED;

    return CDCE_RC__OK;
}

CDCE_Rc CDCE_start(void)
{
    if (CDCE_STATE__CONFIGURED != currentState)
    {
        return CDCE_RC__E_NOT_INITED;
    }

    nextState = CDCE_STATE__BOOTING;

    while (true)
    {
        if (CDCE_STATE__ERROR == nextState)
        {
            break;
        }
        else if (CDCE_STATE__NONE != nextState)
        {
            changeState(nextState);
        }
    }

    /*
     * This statement is only executed if an error occurred and the emulator
     *  will switch to ERROR state.
     *
     * TODO: implement error handling to see what caused the problem
     */
    return CDCE_RC__E_UNKNOWN;
}

CDCE_Rc CDCE_periodic(void)
{
    //TODO implement later, when periodic events are generated by timer interrupts...

    //TODO: sending periodic message according to the current state...

    return CDCE_RC__OK;
}
