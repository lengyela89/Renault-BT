/*
 * CDCEmulator.h
 *
 *  Created on: Feb 10, 2019
 *      Author: lengyela
 */

#ifndef CDCEMULATOR_INC_CDCEMULATOR_H_
#define CDCEMULATOR_INC_CDCEMULATOR_H_


//-------- Includes ---------------------------------------------------------//
#include <stdbool.h>
#include <stm32f1xx_hal.h>

//-------- Defines ----------------------------------------------------------//
#define CDCE_RC__OK							0u
#define CDCE_RC__CONFIGURING_NOT_ALLOWED	1u
#define CDCE_RC__INVALID_UART_HANDLE		2u
#define CDCE_RC__INVALID_EVENT_HANDLER		3u
#define CDCE_RC__E_NOT_INITED				4u
#define CDCE_RC__E_NOT_PLAYING				5u
#define CDCE_RC__INVALID_MESSAGE_TYPE		6u


//-------- Typedefs ---------------------------------------------------------//
typedef void (*CDCE_EventHandler)(void);

typedef struct {
	UART_HandleTypeDef  *huart;
	CDCE_EventHandler	eventHandler;
} CDCE_Config;

typedef uint8_t CDCE_Rc;


//-------- Function prototypes ----------------------------------------------//
CDCE_Rc CDCE_configure(CDCE_Config);

CDCE_Rc CDCE_start(void);

CDCE_Rc CDCE_periodic(void);


#endif /* CDCEMULATOR_INC_CDCEMULATOR_H_ */
