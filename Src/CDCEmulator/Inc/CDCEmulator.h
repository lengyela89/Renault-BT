/*
 * CDCEmulator.h
 *
 *  Created on: Feb 10, 2019
 *      Author: lengyela
 */

#ifndef CDCEMULATOR_INC_CDCEMULATOR_H_
#define CDCEMULATOR_INC_CDCEMULATOR_H_


/* -- Includes ----------------------------------------------------------------------- */
#include <stdbool.h>
#include <stm32f1xx_hal.h>

/* -- Defines ------------------------------------------------------------------------ */
//Error codes for CDC emulator
#define CDCE_RC__OK                         0u
#define CDCE_RC__E_CONFIGURING_NOT_ALLOWED  1u
#define CDCE_RC__E_INVALID_UART_HANDLE      2u
#define CDCE_RC__E_INVALID_EVENT_HANDLER    3u
#define CDCE_RC__E_NOT_INITED               4u
#define CDCE_RC__E_NOT_PLAYING              5u
#define CDCE_RC__E_INVALID_MESSAGE_TYPE     6u
#define CDCE_RC__E_UNKNOWN                  7u              //TODO remove as soon as possible


/* -- Typedefs ----------------------------------------------------------------------- */
typedef void (*CDCE_EventHandler)(void);

typedef struct {
    UART_HandleTypeDef  *huart;
    CDCE_EventHandler   eventHandler;
} CDCE_Config;

typedef uint8_t CDCE_Rc;


/* -- Prototypes --------------------------------------------------------------------- */
/**
 * Configures the CDC emulator according to the given configuration.
 *
 * @param cfg The configuration descriptor for the CDC emulator
 */
CDCE_Rc CDCE_configure(CDCE_Config cfg);

/**
 * Starts the CDC emulator.
 */
CDCE_Rc CDCE_start(void);

/**
 * Should be called periodically; ensures the sending of periodic
 *  messages from CDC emulator to the HU.
 *
 *  !Currently not used!
 */
CDCE_Rc CDCE_periodic(void);


#endif /* CDCEMULATOR_INC_CDCEMULATOR_H_ */
