/*
 * CDCDEMessage.c
 *
 *  Created on: Feb 24, 2019
 *      Author: lengyela
 */


/* -- Includes ----------------------------------------------------------------------- */
#include <CDCEMessage.h>
#include <CDCEmulator.h>
#include <stdbool.h>
#include <stdarg.h>

/* -- Defines ------------------------------------------------------------------------ */

/* -- Typedefs ----------------------------------------------------------------------- */

/* -- Variables ---------------------------------------------------------------------- */

/* -- Prototypes --------------------------------------------------------------------- */

/* -- Functions ---------------------------------------------------------------------- */
CDCEM_Rc CDCEM_clearMessage(CDCEM_Message message)
{
    if (NULL == message)
    {
        return CDCEM_RC__E_NULL;
    }


    for (CDCEM_Idx i = 0u; i < CDCEM_MESSAGE_SIZE__MAX; i++)
    {
        message[i] = 0u;
    }

    return CDCEM_RC__OK;
}

CDCEM_Rc CDCEM_createAck(CDCEM_Message message)
{
    if (NULL == message)
    {
        return CDCEM_RC__E_NULL;
    }


    message[CDCEM_IDX__HEADER] = CDCEM_HEADER__ACK;

    return CDCEM_RC__OK;
}

CDCEM_Rc CDCEM_createFrame(CDCEM_Message message, CDCEM_FrameId frameId,
        CDCEM_PayloadType payloadType, ...)
{
    CDCEM_Rc    cdcemRc = CDCEM_RC__OK;
    uint8_t     length  = 0u;
    va_list     args;


    if (NULL == message)
    {
        return CDCEM_RC__E_NULL;
    }


    cdcemRc = CDCEM_getCDCPayloadLength(payloadType, &length);
    if (CDCEM_RC__OK != cdcemRc)
    {
        return cdcemRc;
    }

    message[CDCEM_IDX__HEADER]       = CDCEM_HEADER__FRAME;
    message[CDCEM_IDX__FRAME_ID]     = frameId;
    message[CDCEM_IDX__DATA_LEN]     = length + 1u;
    message[CDCEM_IDX__PAYLOAD_TYPE] = payloadType;

    va_start(args, payloadType);
    for (uint8_t i = 4u; i < (4 + length); i++)
    {
        message[i] = va_arg(args, int);
    }
    va_end(args);

    cdcemRc = CDCEM_refreshCRC(message);
    if (CDCEM_RC__OK != cdcemRc)
    {
        return cdcemRc;
    }

    return CDCEM_RC__OK;
}

bool CDCEM_isACK(CDCEM_Message message)
{
    if ((NULL != message) && (CDCEM_HEADER__ACK == message[CDCEM_IDX__HEADER]))
    {
        return true;
    }

    return false;
}

bool CDCEM_isFrame(CDCEM_Message message)
{
    if ((NULL != message)
            && (CDCEM_HEADER__FRAME == message[CDCEM_IDX__HEADER]))
    {
        return true;
    }

    return false;
}

bool CDCEM_isValidHUMessage(CDCEM_Message message)
{
    if (CDCEM_isACK(message))
    {
        return true;
    }
    else if (CDCEM_isFrame(message))
    {
        CDCEM_Rc cdcemRc        = CDCEM_RC__OK;
        bool     result         = true;
        uint8_t  payloadLength  = 0u;

        /*
         * Checks the payload-type and if it's valid it returns with the length of the payload;
         *  otherwise an error code is returned (and 0 for payload length).
         */
        cdcemRc = CDCEM_getHUPayloadLength(message[CDCEM_IDX__PAYLOAD_TYPE],
                &payloadLength);
        result &= (CDCEM_RC__OK == cdcemRc);

        result &= (message[CDCEM_IDX__DATA_LEN] == (payloadLength + 1u));

        cdcemRc = CDCEM_checkCRC(message);
        result &= (CDCEM_RC__OK == cdcemRc);

        return result;
    }

    return false;
}

CDCEM_Rc CDCEM_getMessageLength(CDCEM_Message message,
        CDCEM_MessageLength *length)
{
    if ((NULL == message) || (NULL == length))
    {
        return CDCEM_RC__E_NULL;
    }


    if (CDCEM_isValidHUMessage(message))
    {
        return CDCEM_RC__E_MESSAGE_INVALID;
    }

    *length = message[CDCEM_IDX__DATA_LEN] + 4u;

    return CDCEM_RC__OK;
}

CDCEM_Rc CDCEM_getCDCPayloadLength(CDCEM_PayloadType payloadType,
        CDCEM_PayloadLength *length)
{
    if (NULL == length)
    {
        return CDCEM_RC__E_NULL;
    }


    switch (payloadType)
    {
    case CDCEM_PAYLOAD_TYPE__BOOTING:
        *length = 2;
        break;

    case CDCEM_PAYLOAD_TYPE__BOOT_OK:
        *length = 2;
        break;

    case CDCEM_PAYLOAD_TYPE__CD_CHECK:
        *length = 2;
        break;

    case CDCEM_PAYLOAD_TYPE__CD_OPERATION:
        *length = 1;
        break;

    case CDCEM_PAYLOAD_TYPE__CD_SUMMARY:
        *length = 6;
        break;

    case CDCEM_PAYLOAD_TYPE__PLAYING:
        *length = 10;
        break;

    case CDCEM_PAYLOAD_TYPE__RANDOM_STATUS:
        *length = 1;
        break;

    case CDCEM_PAYLOAD_TYPE__STATUS:
        *length = 5;
        break;

    case CDCEM_PAYLOAD_TYPE__TRACK_CHANGE:
        *length = 3;
        break;

    case CDCEM_PAYLOAD_TYPE__TRAY_EJECTION:
        *length = 1;
        break;

    case CDCEM_PAYLOAD_TYPE__TRAY_OPERATION:
        *length = 2;
        break;

    case CDCEM_PAYLOAD_TYPE__TRAY_STATUS:
        *length = 4;
        break;

    default:
        *length = 0;
        return CDCEM_RC__E_UNKNOWN_PAYLOAD_TYPE;
    }

    return CDCEM_RC__OK;
}

CDCEM_Rc CDCEM_getHUPayloadLength(CDCEM_PayloadType payloadType,
        CDCEM_PayloadLength *length)
{
    if (NULL == length)
    {
        return CDCEM_RC__E_NULL;
    }


    switch (payloadType)
    {
    case CDCEM_PAYLOAD_TYPE__START_PLAY:
        *length = 0;
        break;

    case CDCEM_PAYLOAD_TYPE__NEXT_TRACK:
        *length = 1;
        break;

    case CDCEM_PAYLOAD_TYPE__STOP_PLAY:
        *length = 0;
        break;

    case CDCEM_PAYLOAD_TYPE__PAUSE:
        *length = 0;
        break;

    case CDCEM_PAYLOAD_TYPE__FAST_FWD:
        *length = 1;
        break;

    case CDCEM_PAYLOAD_TYPE__FAST_REW:
        *length = 1;
        break;

    case CDCEM_PAYLOAD_TYPE__PREV_TRACK:
        *length = 2;
        break;

    case CDCEM_PAYLOAD_TYPE__NEXT_CD:
        *length = 0;
        break;

    case CDCEM_PAYLOAD_TYPE__LOAD_CD:
        *length = 1;
        break;

    case CDCEM_PAYLOAD_TYPE__SET_RANDOM:
        *length = 2;
        break;

    case CDCEM_PAYLOAD_TYPE__REQ_CD_INFO:
        *length = 0;
        break;

    case CDCEM_PAYLOAD_TYPE__HU_ON:
        *length = 0;
        break;

    case CDCEM_PAYLOAD_TYPE__REQ_CD_CHECK:
        *length = 1;
        break;

    default:
        *length = 0;
        return CDCEM_RC__E_UNKNOWN_PAYLOAD_TYPE;
    }

    return CDCEM_RC__OK;
}


//TODO dataLength type;
CDCEM_Rc CDCEM_dataLengthRangeCheck(CDCEM_Message message)
{
    if (NULL == message)
    {
        return CDCEM_RC__E_NULL;
    }


    if ((CDCEM_DATA_LEN__MIN <= message[CDCEM_IDX__DATA_LEN])
            && (message[CDCEM_IDX__DATA_LEN] <= CDCEM_DATA_LEN__MAX))
    {
        return CDCEM_RC__OK;
    }

    return CDCEM_RC__E_DATA_LEN_RANGE_CHECK;
}

CDCEM_Rc CDCEM_calculateCRC(CDCEM_Message message, CDCEM_Crc *crc,
        CDCEM_Idx *idx)
{
    CDCEM_Rc cdcemRc = CDCEM_RC__OK;


    if ((NULL == message) || (NULL == crc) || (NULL == idx))
    {
        return CDCEM_RC__E_NULL;
    }


    cdcemRc = CDCEM_getCRCIndex(message, idx);
    if (CDCEM_RC__OK != cdcemRc)
    {
        return cdcemRc;
    }

    *crc = message[CDCEM_IDX__HEADER];

    for (uint8_t i = 1u; i < (*idx); i++)
    {
        *crc ^= message[i];
    }

    return CDCEM_RC__OK;
}

CDCEM_Rc CDCEM_refreshCRC(CDCEM_Message message)
{
    CDCEM_Rc    cdcemRc = CDCEM_RC__OK;
    CDCEM_Crc   crc     = 0u;
    CDCEM_Idx   crcIdx  = 0u;


    cdcemRc = CDCEM_calculateCRC(message, &crc, &crcIdx);
    if (CDCEM_RC__OK != cdcemRc)
    {
        return cdcemRc;
    }

    message[crcIdx] = crc;

    return CDCEM_RC__OK;
}

CDCEM_Rc CDCEM_checkCRC(CDCEM_Message message)
{
    CDCE_Rc cdcemRc;
    uint8_t crc, idx;


    cdcemRc = CDCEM_calculateCRC(message, &crc, &idx);
    if (CDCEM_RC__OK != cdcemRc)
    {
        return cdcemRc;
    }

    return (message[idx] == crc ? CDCEM_RC__OK : CDCEM_RC__E_CRC);
}

CDCEM_Rc CDCEM_getCRCIndex(CDCEM_Message message, CDCEM_Idx *crcIndex)
{
    CDCEM_Rc cdcemRc;


    if ((NULL == message) || (NULL == crcIndex))
    {
        return CDCEM_RC__E_NULL;
    }


    cdcemRc = CDCEM_dataLengthRangeCheck(message);
    if (CDCEM_RC__OK != cdcemRc)
    {
        return cdcemRc;
    }

    *crcIndex = message[CDCEM_IDX__DATA_LEN] + 3u;

    return CDCEM_RC__OK;
}

CDCEM_Rc CDCEM_setFrameId(CDCEM_Message message, CDCEM_FrameId frameId)
{
    if (NULL == message)
    {
        return CDCEM_RC__E_NULL;
    }


    message[CDCEM_IDX__FRAME_ID] = frameId;

    return CDCEM_RC__OK;
}
