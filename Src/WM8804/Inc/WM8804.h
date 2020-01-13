/*
 * WM8804.h
 *
 *  Created on: Feb 2, 2019
 *      Author: lengyela
 */

#ifndef WM8804_H_
#define WM8804_H_

#include "stm32f1xx_hal.h"
#include <stdbool.h>


#define WM8804_I2C__ADDRESS_START   0x74u
#define WM8804_I2C__ADDRESS_END     0x77u
#define WM8804_I2C__RETRY           0x03u       // I2C number of retries
#define WM8804_I2C__TIMEOUT         100u        // I2C timeout in ms

#define WM8804_RC__OK                   0u
#define WM8804_RC__E_HAL                1u
#define WM8804_RC__E_NULL               2u
#define WM8804_RC__E_NOT_INITED         3u
#define WM8804_RC__E_INVALID_ADDRESS    4u



typedef uint32_t WM8804_Rc;
typedef uint16_t WM8804_DeviceAddr;
typedef uint8_t  WM8804_RegisterAddr;

typedef uint8_t WM8804_registerRaw_t;

typedef struct {
    GPIO_TypeDef*   GPIOPeripheral;
    uint16_t        GPIOPin;
    bool            activeLow;
} WM8804_ResetPinConfig;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t RST__DEVID1 : 8;
    } R;
} WM8804_R00_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t DEVID2 : 8;
    } R;
} WM8804_R01_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t DEVREV  : 4;
        uint8_t         : 4;
    } R;
} WM8804_R02_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t PLL_K__7_0 : 8;
    } R;
} WM8804_R03_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t PLL_K__15_8 : 8;
    } R;
} WM8804_R04_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t PLL_K__21_16    : 6;
        uint8_t                 : 2;
    } R;
} WM8804_R05_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t PLL_N       : 4;
        uint8_t PRESCALE    : 1;
        uint8_t TXVAL_SF0   : 1;
        uint8_t TXVAL_SF1   : 1;
        uint8_t TXVAL_OVWR  : 1;
    } R;
} WM8804_R06_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t FREQMODE    : 2;
        uint8_t FRACEN      : 1;
        uint8_t MCLKDIV     : 1;
        uint8_t CLKOUTDIV   : 2;
        uint8_t             : 2;
    } R;
} WM8804_R07_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t             : 3;
        uint8_t CLKOUTSRC   : 1;
        uint8_t CLKOUTDIS   : 1;
        uint8_t FILLMODE    : 1;
        uint8_t ALWAYSVALID : 1;
        uint8_t MCLKSRC     : 1;
    } R;
} WM8804_R08_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t SPDIFINMODE : 1;
        uint8_t             : 7;
    } R;
} WM8804_R09_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t MASK    : 8;
    } R;
} WM8804_R10_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t UPD_UNLOCK      : 1;
        uint8_t INT_INVALID     : 1;
        uint8_t INT_CSUD        : 1;
        uint8_t INT_TRANS_ERR   : 1;
        uint8_t UPD_NON_AUDIO   : 1;
        uint8_t UPD_CPY_EN      : 1;
        uint8_t UPD_DEEMPH      : 1;
        uint8_t UPD_REC_FREQ    : 1;
    } R;
} WM8804_R11_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t AUDIO_N     : 1;
        uint8_t PCM_N       : 1;
        uint8_t CPY_N       : 1;
        uint8_t DEEMPH      : 1;
        uint8_t REC_FREQ    : 2;
        uint8_t UNLOCK      : 1;
        uint8_t             : 1;
    } R;
} WM8804_R12_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t CON_PRO     : 1;
        uint8_t AUDIO_N     : 1;
        uint8_t CPY_N       : 1;
        uint8_t DEEMPH      : 1;
        uint8_t             : 2;
        uint8_t CHSTMODE    : 2;
    } R;
} WM8804_R13_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t CATCODE : 8;
    } R;
} WM8804_R14_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t SRCNUM  : 4;
        uint8_t CHNUM2  : 2;
        uint8_t CHNUM1  : 2;
    } R;
} WM8804_R15_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t FREQ    : 4;
        uint8_t CLKACU  : 2;
        uint8_t         : 2;
    } R;
} WM8804_R16_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t MAXWL   : 1;
        uint8_t RXWL    : 3;
        uint8_t ORGSAMP : 4;
    } R;
} WM8804_R17_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t CON_PRO     : 1;
        uint8_t AUDIO_N     : 1;
        uint8_t CPY_N       : 1;
        uint8_t DEEMPH      : 3;
        uint8_t CHSTMODE    : 2;
    } R;
} WM8804_R18_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t CATCODE : 8;
    } R;
} WM8804_R19_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t SRCNUM  : 4;
        uint8_t CHNUM1  : 2;
        uint8_t CHNUM2  : 2;
    } R;
} WM8804_R20_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t FREQ        : 4;
        uint8_t CLKACU      : 2;
        uint8_t TXSRC       : 1;
        uint8_t TXSTATSRC   : 1;
    } R;
} WM8804_R21_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t MAXWL   : 1;
        uint8_t TXWL    : 3;
        uint8_t ORGSAMP : 4;
    } R;
} WM8804_R22_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t GPO0    : 4;
        uint8_t         : 4;
    } R;
} WM8804_R23_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t GPO1    : 4;
        uint8_t         : 4;
    } R;
} WM8804_R24_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t : 8;
    } R;
} WM8804_R25_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t         : 4;
        uint8_t GPO2    : 4;
    } R;
} WM8804_R26_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t AIFTX_FMT   : 2;
        uint8_t AIFTX_WL    : 2;
        uint8_t AIFTX_BCP   : 1;
        uint8_t AIFTX_LRP   : 1;
        uint8_t             : 2;
    } R;
} WM8804_R27_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t AIFRX_FMT   : 2;
        uint8_t AIFRX_WL    : 2;
        uint8_t AIFRX_BCP   : 1;
        uint8_t AIFRX_LRP   : 1;
        uint8_t AIF_MS      : 1;
        uint8_t SYNC_OFF    : 1;
    } R;
} WM8804_R28_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t READMUX     : 3;
        uint8_t CONT        : 1;
        uint8_t WITHFLAG    : 1;
        uint8_t             : 1;
        uint8_t WL_MASK     : 1;
        uint8_t SPD_192K_EN : 1;
    } R;
} WM8804_R29_t;

typedef union {
    WM8804_registerRaw_t raw;
    struct {
        uint8_t PLLPD       : 1;
        uint8_t SPDIFRXPD   : 1;
        uint8_t SPDIFTXPD   : 1;
        uint8_t OSCPD       : 1;
        uint8_t AIFPD       : 1;
        uint8_t TRIOP       : 1;
        uint8_t             : 2;
    } R;
} WM8804_R30_t;

//TODO
typedef struct {
    WM8804_R00_t RST__DEVID1;       //Write for RESET; Read device ID
    WM8804_R01_t DEVID2;            //Readonly
    WM8804_R02_t DEVREV;            //Readonly
    WM8804_R03_t PLL1;
    WM8804_R04_t PLL2;
    WM8804_R05_t PLL3;
    WM8804_R06_t PLL4;
    WM8804_R07_t PLL5;
    WM8804_R08_t PLL6;
    WM8804_R09_t SPDMODE;
    WM8804_R10_t INTMASK;
    WM8804_R11_t INTSTAT;           //Readonly
    WM8804_R12_t SPDSTAT;           //Readonly
    WM8804_R13_t RXCHAN1;           //Readonly
    WM8804_R14_t RXCHAN2;           //Readonly
    WM8804_R15_t RXCHAN3;           //Readonly
    WM8804_R16_t RXCHAN4;           //Readonly
    WM8804_R17_t RXCHAN5;           //Readonly
    WM8804_R18_t SPDTX1;
    WM8804_R19_t SPDTX2;
    WM8804_R20_t SPDTX3;
    WM8804_R21_t SPDTX4;
    WM8804_R22_t SPDTX5;
    WM8804_R23_t GPO0;
    WM8804_R24_t GPO1;
    WM8804_R26_t GPO2;
    WM8804_R27_t AIFTX;
    WM8804_R28_t AIFRX;
    WM8804_R29_t SPDRX1;
    WM8804_R30_t PWRDN;
} WM8804_registers_t;

typedef enum {
    REG_RST__DEVID1 = 0x00u,
    REG_DEVID2      = 0x01u,
    REG_DEVREV      = 0x02u,
    REG_PLL1        = 0x03u,
    REG_PLL2        = 0x04u,
    REG_PLL3        = 0x05u,
    REG_PLL4        = 0x06u,
    REG_PLL5        = 0x07u,
    REG_PLL6        = 0x08u,
    REG_SPDMODE     = 0x09u,
    REG_INTMASK     = 0x0Au,
    REG_INTSTAT     = 0x0Bu,
    REG_SPDSTAT     = 0x0Cu,
    REG_RXCHAN1     = 0x0Du,
    REG_RXCHAN2     = 0x0Eu,
    REG_RXCHAN3     = 0x0Fu,
    REG_RXCHAN4     = 0x10u,
    REG_RXCHAN5     = 0x11u,
    REG_SPDTX1      = 0x12u,
    REG_SPDTX2      = 0x13u,
    REG_SPDTX3      = 0x14u,
    REG_SPDTX4      = 0x15u,
    REG_SPDTX5      = 0x16u,
    REG_GPO0        = 0x17u,
    REG_GPO1        = 0x18u,
    REG_GPO2        = 0x1Au,
    REG_AIFTX       = 0x1Bu,
    REG_AIFRX       = 0x1Cu,
    REG_SPDRX1      = 0x1Du,
    REG_PWRDN       = 0x1Eu
} WM8804_Register;


#define REG_PLL1__INIT          0b00100001
#define REG_PLL2__INIT          0b11111101
#define REG_PLL3__INIT          0b00110110
#define REG_PLL4__INIT          0b00000111
#define REG_PLL5__INIT          0b00010110
#define REG_PLL6__INIT          0b00011000
#define REG_SPDMODE__INIT       0b11111111
#define REG_INTMASK__INIT       0b00000000
#define REG_SPDTX1__INIT        0b00000000
#define REG_SPDTX2__INIT        0b00000000
#define REG_SPDTX3__INIT        0b00000000
#define REG_SPDTX4__INIT        0b01110001
#define REG_SPDTX5__INIT        0b00001011
#define REG_GPO0__INIT          0b01110000
#define REG_GPO1__INIT          0b01010111
#define REG_GPO2__INIT          0b01000010
#define REG_AIFTX__INIT         0b00000110
#define REG_AIFRX__INIT         0b00000110
#define REG_SPDRX1__INIT        0b10000000
#define REG_PWRDN__INIT         0b00000111


WM8804_Rc WM8804_initialize(I2C_HandleTypeDef *hi2c, WM8804_DeviceAddr deviceAddress, WM8804_ResetPinConfig resetPinConfig);
void WM8804_clearRegisterConfigs(void);
WM8804_Rc WM8804_doHardwareReset(void);
WM8804_Rc WM8804_getRegisterConfigs(WM8804_registers_t **registerConfigs);
WM8804_Rc WM8804_getDeviceAddress(I2C_HandleTypeDef *hi2c, uint16_t *devAddr);

#endif /* WM8804_H_ */
