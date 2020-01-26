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
#define CDCEM_MESSAGE_SIZE__MAX	    0x0Fu               //Maximum size of a message

#define CDCEM_DATA_LEN__MIN	        0x01u               //Minimum length of data in a message
#define CDCEM_DATA_LEN__MAX	        0x0Bu               //Maximum length of data in a message

//Possible values for message header
#define CDCEM_HEADER__FRAME	        0x3Du               //Header value for frames
#define CDCEM_HEADER__ACK           0xC5u               //Header value for ACKs

//Positions of the main parts of the message/frame
#define CDCEM_IDX__HEADER           0x00u
#define CDCEM_IDX__FRAME_ID         0x01u
#define CDCEM_IDX__DATA_LEN         0x02u
#define CDCEM_IDX__PAYLOAD_TYPE     0x03u
#define CDCEM_IDX__PAYLOAD_DATA     0x04u

//Payload-types for CDC messages/frames
#define CDCEM_PAYLOAD_TYPE__BOOTING         0x11u
#define CDCEM_PAYLOAD_TYPE__CD_CHECK        0x13u
#define CDCEM_PAYLOAD_TYPE__BOOT_OK	        0x15u
#define CDCEM_PAYLOAD_TYPE__STATUS          0x20u
#define CDCEM_PAYLOAD_TYPE__CD_OPERATION    0x21u
#define CDCEM_PAYLOAD_TYPE__TRAY_OPERATION  0x22u
#define CDCEM_PAYLOAD_TYPE__TRAY_EJECTION   0x23u
#define CDCEM_PAYLOAD_TYPE__RANDOM_STATUS   0x25u
#define CDCEM_PAYLOAD_TYPE__TRAY_STATUS     0x26u
#define CDCEM_PAYLOAD_TYPE__TRACK_CHANGE    0x27u
#define CDCEM_PAYLOAD_TYPE__CD_SUMMARY      0x46u
#define CDCEM_PAYLOAD_TYPE__PLAYING         0x47u

//Payload-types for HU messages/frames
#define CDCEM_PAYLOAD_TYPE__START_PLAY      0x13u
#define CDCEM_PAYLOAD_TYPE__NEXT_TRACK      0x17u
#define CDCEM_PAYLOAD_TYPE__STOP_PLAY       0x19u
#define CDCEM_PAYLOAD_TYPE__PAUSE           0x1Cu
#define CDCEM_PAYLOAD_TYPE__FAST_FWD        0x20u
#define CDCEM_PAYLOAD_TYPE__FAST_REW        0x21u
#define CDCEM_PAYLOAD_TYPE__PREV_TRACK      0x22u
#define CDCEM_PAYLOAD_TYPE__NEXT_CD         0x24u
#define CDCEM_PAYLOAD_TYPE__LOAD_CD         0x26u
#define CDCEM_PAYLOAD_TYPE__SET_RANDOM      0x27u
#define CDCEM_PAYLOAD_TYPE__REQ_CD_INFO     0x86u
#define CDCEM_PAYLOAD_TYPE__HU_ON           0x93u
#define CDCEM_PAYLOAD_TYPE__REQ_CD_CHECK    0x94u

//Error codes
#define CDCEM_RC__OK                        0x00u
#define CDCEM_RC__E_UNKNOWN_PAYLOAD_TYPE    0x01u
#define CDCEM_RC__E_DATA_LEN_RANGE_CHECK    0x02u
#define CDCEM_RC__E_NULL                    0x03u
#define CDCEM_RC__E_MESSAGE_INVALID	        0x04u
#define CDCEM_RC__E_CRC                     0x05u

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
/**
 * Clears the given message (sets every element in the array to 0).
 *
 * @param message The message which will be cleared
 */
CDCEM_Rc CDCEM_clearMessage(CDCEM_Message message);

/**
 * Creates an ACK message into the given output parameter
 *
 * @param[out] message The variable which will store the created message
 */
CDCEM_Rc CDCEM_createAck(CDCEM_Message message);

/**
 * Creates a new message into the output parameter with the given frame id, payload type
 *  and additional parameters.
 *
 * @param[out]  message     The variable which will store the created message
 * @param[in]   frameId     The frame id of the created message
 * @param[in]   payloadType The payload type of the created message
 * @param[in]   args...     Further parameters for the created message
 */
CDCEM_Rc CDCEM_createFrame(CDCEM_Message message, CDCEM_FrameId frameId, CDCEM_PayloadType payloadType, ...);

/**
 * Returns TRUE, if the message is not NULL and it is an ACK message;
 *  otherwise it returns FALSE.
 *
 * @param message The examined message
 */
bool CDCEM_isACK(CDCEM_Message message);

/**
 * Returns TRUE, if the message is not NULL and it is a FRAME message;
 *  otherwise it returns FALSE.
 *
 * @param message The examined message
 */
bool CDCEM_isFrame(CDCEM_Message message);

/**
 * Checks, if the given message is a valid HU message or not (HU message: a message that was
 *  sent by the head-unit).
 *
 * @param message The examined message
 */
bool CDCEM_isValidHUMessage(CDCEM_Message message);

/**
 * Returns the full length of the given message if it is a valid message;
 *  otherwise an error code is returned.
 *
 * @param[in]   message The message of which the length is retrieved
 * @param[out]  length  The length of the given message
 */
CDCEM_Rc CDCEM_getMessageLength(CDCEM_Message message, CDCEM_MessageLength *length);

/**
 * Returns the length of the payload for the given payload-type, if it's a valid CDC
 *  payload-type; otherwise an error code is returned.
 *
 * @param[in]   payloadType The payload-type of which the length is retrieved
 * @param[out]  length      The length of the selected payload-type
 */
CDCEM_Rc CDCEM_getCDCPayloadLength(CDCEM_PayloadType payloadType, CDCEM_PayloadLength *length);

/**
 * Returns the length of the payload for the given payload-type, if it's a valid HU
 *  payload-type; otherwise an error code is returned.
 *
 * @param[in]   payloadType The payload-type of which the length is retrieved
 * @param[out]  length      The length of the selected payload-type
 */
CDCEM_Rc CDCEM_getHUPayloadLength(CDCEM_PayloadType payloadType, CDCEM_PayloadLength *length);

/**
 * Checks, if the data length parameter of the given message is in the valid range.
 *
 * @param message The examined message
 */
CDCEM_Rc CDCEM_dataLengthRangeCheck(CDCEM_Message message);

/**
 * Calculates the CRC for the given message and returns it with its internal position
 *  as output parameters.
 *
 * @param[in]   message The message for which the CRC is calculated
 * @param[out]  crc     The calculated CRC value
 * @para,[out]  idx     The position of the CRC field within the message structure
 *                       (according to the selected payload-type)
 */
CDCEM_Rc CDCEM_calculateCRC(CDCEM_Message message, CDCEM_Crc *crc, CDCEM_Idx *idx);

/**
 * Updates the CRC field of the given message.
 *
 * @param   message The message for which the CRC is calculated and updated
 */
CDCEM_Rc CDCEM_refreshCRC(CDCEM_Message message);

/**
 * Checks, whether the CRC value that belongs to the message is valid, or not.
 *
 * @param   message The examined message
 */
CDCEM_Rc CDCEM_checkCRC(CDCEM_Message message);

/**
 * Returns the position of the CRC field within the message structure
 *  (according to the selected payload-type).
 *
 * @param[in]   message     The examined message
 * @param[out]  crcIndex    The position of the CRC field within the given message
 */
CDCEM_Rc CDCEM_getCRCIndex(CDCEM_Message message, CDCEM_Idx *crcIndex);

/**
 * Sets the frame id of the message to the given value.
 *
 * @param   message The message for which the frame id is set
 * @param   frameId The frame id value for the message
 */
CDCEM_Rc CDCEM_setFrameId(CDCEM_Message message, CDCEM_FrameId frameId);

#endif /* CDCEMULATOR_INC_CDCEMESSAGE_H_ */
