/*
 * CDCEMessage.h
 *
 *  Created on: Feb 24, 2019
 *      Author: lengyela
 */

#ifndef CDCEMULATOR_INC_CDCEMESSAGE_H_
#define CDCEMULATOR_INC_CDCEMESSAGE_H_


/* -- Includes ----------------------------------------------------------------------- */
#include <stdbool.h>
#include <stm32f1xx_hal.h>


/* -- Defines ------------------------------------------------------------------------ */
#define CDCEM_MESSAGE_SIZE__MAX		0x0Fu

#define CDCEM_DATA_LEN__MIN			0x01u
#define CDCEM_DATA_LEN__MAX			0x0Bu


#define CDCEM_HEADER__FRAME			0x3Du
#define CDCEM_HEADER__ACK			0xC5u


#define CDCEM_IDX__HEADER			0x00u
#define CDCEM_IDX__FRAME_ID			0x01u
#define CDCEM_IDX__DATA_LEN			0x02u
#define CDCEM_IDX__PAYLOAD_TYPE		0x03u
#define CDCEM_IDX__PAYLOAD_DATA		0x04u


#define CDCEM_PAYLOAD_TYPE__BOOTING			0x11u
#define CDCEM_PAYLOAD_TYPE__CD_CHECK		0x13u
#define CDCEM_PAYLOAD_TYPE__BOOT_OK			0x15u
#define CDCEM_PAYLOAD_TYPE__STATUS			0x20u
#define CDCEM_PAYLOAD_TYPE__CD_OPERATION	0x21u
#define CDCEM_PAYLOAD_TYPE__TRAY_OPERATION	0x22u
#define CDCEM_PAYLOAD_TYPE__TRAY_EJECTION	0x23u
#define CDCEM_PAYLOAD_TYPE__RANDOM_STATUS	0x25u
#define CDCEM_PAYLOAD_TYPE__TRAY_STATUS		0x26u
#define CDCEM_PAYLOAD_TYPE__TRACK_CHANGE	0x27u
#define CDCEM_PAYLOAD_TYPE__CD_SUMMARY		0x46u
#define CDCEM_PAYLOAD_TYPE__PLAYING			0x47u

#define CDCEM_PAYLOAD_TYPE__START_PLAY		0x13u
#define CDCEM_PAYLOAD_TYPE__NEXT_TRACK		0x17u
#define CDCEM_PAYLOAD_TYPE__STOP_PLAY		0x19u
#define CDCEM_PAYLOAD_TYPE__PAUSE			0x1Cu
#define CDCEM_PAYLOAD_TYPE__FAST_FWD		0x20u
#define CDCEM_PAYLOAD_TYPE__FAST_REW		0x21u
#define CDCEM_PAYLOAD_TYPE__PREV_TRACK		0x22u
#define CDCEM_PAYLOAD_TYPE__NEXT_CD			0x24u
#define CDCEM_PAYLOAD_TYPE__LOAD_CD			0x26u
#define CDCEM_PAYLOAD_TYPE__SET_RANDOM		0x27u
#define CDCEM_PAYLOAD_TYPE__REQ_CD_INFO		0x86u
#define CDCEM_PAYLOAD_TYPE__HU_ON			0x93u
#define CDCEM_PAYLOAD_TYPE__REQ_CD_CHECK	0x94u


#define CDCEM_RC__OK						0x00u
#define CDCEM_RC__E_UNKNOWN_PAYLOAD_TYPE	0x01u
#define CDCEM_RC__E_DATA_LEN_RANGE_CHECK	0x02u
#define CDCEM_RC__E_NULL					0x03u
#define CDCEM_RC__E_MESSAGE_INVALID			0x04u
#define CDCEM_RC__E_CRC						0x05u


/* -- Typedefs ----------------------------------------------------------------------- */
typedef uint8_t CDCEM_Rc;
typedef uint8_t CDCEM_Crc;
typedef uint8_t CDCEM_Idx;
typedef uint8_t CDCEM_FrameId;
typedef uint8_t CDCEM_Message[CDCEM_MESSAGE_SIZE__MAX];
typedef uint8_t CDCEM_MessageLength;
typedef uint8_t CDCEM_PayloadType;
typedef uint8_t CDCEM_PayloadLength;


/* -- Prototypes --------------------------------------------------------------------- */
CDCEM_Rc CDCEM_clearMessage(CDCEM_Message message);
CDCEM_Rc CDCEM_createAck(CDCEM_Message message);
CDCEM_Rc CDCEM_createFrame(CDCEM_Message message, CDCEM_FrameId frameId, CDCEM_PayloadType payloadType, ...);
bool CDCEM_isACK(CDCEM_Message message);
bool CDCEM_isFrame(CDCEM_Message message);
bool CDCEM_isValidHUMessage(CDCEM_Message message);
CDCEM_Rc CDCEM_getMessageLength(CDCEM_Message message, CDCEM_MessageLength *length);
CDCEM_Rc CDCEM_getCDCPayloadLength(CDCEM_PayloadType payloadType, CDCEM_PayloadLength *length);
CDCEM_Rc CDCEM_getHUPayloadLength(CDCEM_PayloadType payloadType, CDCEM_PayloadLength *length);
CDCEM_Rc CDCEM_dataLengthRangeCheck(CDCEM_Message message);
CDCEM_Rc CDCEM_calculateCRC(CDCEM_Message message, CDCEM_Crc *crc, CDCEM_Idx *idx);
CDCEM_Rc CDCEM_refreshCRC(CDCEM_Message message);
CDCEM_Rc CDCEM_checkCRC(CDCEM_Message message);
CDCEM_Rc CDCEM_getCRCIndex(CDCEM_Message message, CDCEM_Idx *crcIndex);
CDCEM_Rc CDCEM_setFrameId(CDCEM_Message message, CDCEM_FrameId frameId);

#endif /* CDCEMULATOR_INC_CDCEMESSAGE_H_ */
