/*
 * WM8804.c
 *
 *  Created on: Feb 1, 2019
 *      Author: lengyela
 */

/* -- Includes ----------------------------------------------------------------------- */
#include "WM8804.h"
#include <stm32f1xx_hal_i2c.h>

/* -- Typedefs ----------------------------------------------------------------------- */
typedef struct
{
    I2C_HandleTypeDef       *hi2c;
    WM8804_DeviceAddr       deviceAddress;
    WM8804_ResetPinConfig   resetPinConfig;
    WM8804_registers_t      registers;
    bool                    initialized;
} WM8804_Config;

/* -- Variables ---------------------------------------------------------------------- */
static WM8804_Config config;

/* -- Prototypes --------------------------------------------------------------------- */

/* -- Functions ---------------------------------------------------------------------- */
WM8804_Rc WM8804_initialize(I2C_HandleTypeDef *hi2c, WM8804_DeviceAddr deviceAddress, WM8804_ResetPinConfig resetPinConfig)
{
    if (NULL == hi2c)
    {
        config.initialized = false;

        return WM8804_RC__E_NULL;
    }

    if (WM8804_I2C__ADDRESS_START > deviceAddress || WM8804_I2C__ADDRESS_END < deviceAddress)
    {
        config.initialized = false;

        return WM8804_RC__E_INVALID_ADDRESS;
    }

    config.hi2c = hi2c;
    config.deviceAddress = deviceAddress;
    config.resetPinConfig = resetPinConfig;

    WM8804_clearRegisterConfigs();

    config.initialized = true;

    return WM8804_RC__OK;
}

WM8804_Rc WM8804_configureModule(void)
{
    if (false == config.initialized)
    {
        return WM8804_RC__E_NOT_INITED;
    }


    /*
     * Master clock (MCLK) and clock out (CLKOUT)
     *  frequency configuration:
     *  - MCLK: 6.144MHz
     *  - CLKOUT: 3.072MHz
     */
    config.registers.PLL4.R.TXVAL_OVWR = 0b0;              //S/PDIF Transmitter Validity Overwrite Mode - Disabled
    config.registers.PLL4.R.TXVAL_SF1 = 0b0;               //Overwrite Mode S/PDIF Transmitter Validity Sub-Frame 1 - Transmit validity = 0
    config.registers.PLL4.R.TXVAL_SF0 = 0b0;               //Overwrite Mode S/PDIF Transmitter Validity Sub-Frame 0 - Transmit validity = 0
    config.registers.PLL4.R.PRESCALE = 0b0;                //PLL Pre-scale Divider Select - 0 = Divide by 1 (PLL input clock = oscillator clock)
    config.registers.PLL4.R.PLL_N = 0b1000;                //Integer (N) part of PLL frequency ratio (R) - 8

    //Set PLL_K value to 0x0C49BA
    config.registers.PLL3.R.PLL_K__21_16 = 0b001100;       //Fractional (K) part of PLL frequency ratio (R) [21-16] - 12 (0x0C)
    config.registers.PLL2.R.PLL_K__15_8 = 0b01001001;      //Fractional (K) part of PLL frequency ratio (R) [15-8] - 73 (0x49)
    config.registers.PLL1.R.PLL_K__7_0 = 0b10111010;       //Fractional (K) part of PLL frequency ratio (R) [7-0] - 186 (0xBA)

    config.registers.PLL5.R.CLKOUTDIV = 0b11;              //CLKOUT Divider Select - 11: CLK1 FREQUENCY = 64fs
    config.registers.PLL5.R.MCLKDIV = 0b1;                 //MCLK Divider Select - 1: CLK2 FREQUENCY = 128fs
    config.registers.PLL5.R.FRACEN = 0b1;                  //Integer/Fractional PLL Mode Select - 1 = Fractional PLL (both PLL_N and PLL_K values used)
    config.registers.PLL5.R.FREQMODE = 0b10;               //PLL Post-scale Divider Select - 10

    config.registers.PLL6.R.MCLKSRC = 0b0;                 //MCLK Output Source Select - 0 = Select CLK2
    config.registers.PLL6.R.ALWAYSVALID = 0b0;             //Always Valid Select - 0 = Use INVALID flag
    config.registers.PLL6.R.FILLMODE = 0b0;                //Fill Mode Select - 0 = Data from S/PDIF receiver remains static at last valid sample
    config.registers.PLL6.R.CLKOUTDIS = 0b1;               //CLKOUT Pin Disable - 1 = Pin Enabled
    config.registers.PLL6.R.CLKOUTSRC = 0b0;               //CLKOUT Pin Source Select - 0 = Select CLK1
    /* End of MCLK/CLKOUT configuration part */

    config.registers.SPDTX1.R.CHSTMODE = 0b00;             //Channel status mode - ?
    config.registers.SPDTX1.R.DEEMPH = 0b000;              //Additional Format Information - Data from Audio Interface has no preemphasis - ?
    config.registers.SPDTX1.R.CPY_N = 0b0;                 //Copyright Information - Transmitted data has copyright asserted
    config.registers.SPDTX1.R.AUDIO_N = 0b0;               //Linear PCM identification - S/PDIF transmitted data is audio PCM
    config.registers.SPDTX1.R.CON_PRO = 0b0;               //Use of channel status block - Consumer mode

    config.registers.SPDTX3.R.CHNUM2 = 0b10;               //Send to Right channel
    config.registers.SPDTX3.R.CHNUM1 = 0b01;               //Send to Left channel
    config.registers.SPDTX3.R.SRCNUM = 0b0000;             //Source number - ?

    config.registers.SPDTX4.R.TXSTATSRC = 0b0;
    config.registers.SPDTX4.R.TXSRC = 0b1;                 //Digital Audio Interface Received Data
    config.registers.SPDTX4.R.CLKACU = 0b11;               //Interface frame rate not matched to sampling frequency
    config.registers.SPDTX4.R.FREQ = 0b0001;               //Sampling Frequency not indicated

    config.registers.SPDTX5.R.ORGSAMP = 0b000;             //?
    config.registers.SPDTX5.R.TXWL = 0b001;                //001 (MAXWL==1 => 20 bits)
    config.registers.SPDTX5.R.MAXWL = 0b1;                 //Maximum Audio Sample Word Length - 24 bits

    config.registers.AIFRX.R.SYNC_OFF = 0b1;               //?
    config.registers.AIFRX.R.AIF_MS = 0b1;                 //Master mode
    config.registers.AIFRX.R.AIFRX_LRP = 0b1;              //Invert LRCK polarity
    config.registers.AIFRX.R.AIFRX_BCP = 0b0;              //BCLK not inverted
    config.registers.AIFRX.R.AIFRX_WL = 0b01;              //20 bit
    config.registers.AIFRX.R.AIFRX_FMT = 0b01;             //Left justified mode

    config.registers.PWRDN.R.TRIOP = 0b0;                  //Outputs are not tri-stated
    config.registers.PWRDN.R.AIFPD = 0b0;                  //Digital Audio Interface - Power Up
    config.registers.PWRDN.R.OSCPD = 0b0;                  //Oscillator - Power Up
    config.registers.PWRDN.R.SPDIFTXPD = 0b0;              //S/PDIF Transmitter - Enabled
    config.registers.PWRDN.R.SPDIFRXPD = 0b1;              //S/PDIF Receiver - Disabled
    config.registers.PWRDN.R.PLLPD = 0b0;                  //PLL - Enabled

    return WM8804_writeConfig();
}

void WM8804_clearRegisterConfigs(void)
{
    /* Initialize registers to default values */
    config.registers.PLL1.raw = REG_PLL1__INIT;
    config.registers.PLL2.raw = REG_PLL2__INIT;
    config.registers.PLL3.raw = REG_PLL3__INIT;
    config.registers.PLL4.raw = REG_PLL4__INIT;
    config.registers.PLL5.raw = REG_PLL5__INIT;
    config.registers.PLL6.raw = REG_PLL6__INIT;
    config.registers.SPDMODE.raw = REG_SPDMODE__INIT;
    config.registers.INTMASK.raw = REG_INTMASK__INIT;
    config.registers.SPDTX1.raw = REG_SPDTX1__INIT;
    config.registers.SPDTX2.raw = REG_SPDTX2__INIT;
    config.registers.SPDTX3.raw = REG_SPDTX3__INIT;
    config.registers.SPDTX4.raw = REG_SPDTX4__INIT;
    config.registers.SPDTX5.raw = REG_SPDTX5__INIT;
    config.registers.GPO0.raw = REG_GPO0__INIT;
    config.registers.GPO1.raw = REG_GPO1__INIT;
    config.registers.GPO2.raw = REG_GPO2__INIT;
    config.registers.AIFTX.raw = REG_AIFTX__INIT;
    config.registers.AIFRX.raw = REG_AIFRX__INIT;
    config.registers.SPDRX1.raw = REG_SPDRX1__INIT;
    config.registers.PWRDN.raw = REG_PWRDN__INIT;
}

WM8804_Rc WM8804_getRegisterConfigs(WM8804_registers_t **registerConfigs)
{
    if (false == config.initialized)
    {
        return WM8804_RC__E_NOT_INITED;
    }

    if (NULL == registerConfigs)
    {
        return WM8804_RC__E_NULL;
    }

    *registerConfigs = &config.registers;

    return WM8804_RC__OK;
}

WM8804_Rc WM8804_getDeviceAddress(I2C_HandleTypeDef *hi2c, WM8804_DeviceAddr *devAddr)
{
    HAL_StatusTypeDef status = HAL_ERROR;


    if ((NULL == hi2c) || (NULL == devAddr))
    {
        return WM8804_RC__E_NULL;
    }

    for (WM8804_DeviceAddr i = WM8804_I2C__ADDRESS_START; i <= WM8804_I2C__ADDRESS_END; i++)
    {
        status = HAL_I2C_IsDeviceReady(hi2c, i, WM8804_I2C__RETRY, WM8804_I2C__TIMEOUT);

        if (HAL_OK == status)
        {
            *devAddr = i;

            return WM8804_RC__OK;
        }
    }

    devAddr = WM8804_I2C__ADDRESS_INVALID;

    return WM8804_RC__E_HAL;
}

WM8804_Rc WM8804_doHardwareReset(void)
{
    if (false == config.initialized)
    {
        return WM8804_RC__E_NOT_INITED;
    }


    /* Set RESET pin to the appropriate state to reset WM8804 */
    HAL_GPIO_WritePin(config.resetPinConfig.GPIOPeripheral, config.resetPinConfig.GPIOPin,
            (config.resetPinConfig.activeLow ? GPIO_PIN_RESET : GPIO_PIN_SET));

    /* Wait 5ms */
    HAL_Delay(5u);

    /* Release RESET pin */
    HAL_GPIO_TogglePin(config.resetPinConfig.GPIOPeripheral, config.resetPinConfig.GPIOPin);

    /* Wait 5ms in order to WM8804 initialize; if it initializes in SW mode, configuration can be done after that. */
    HAL_Delay(5u);


    return WM8804_RC__OK;
}

WM8804_Rc WM8804_writeRegister(WM8804_RegisterAddr regAddr, WM8804_registerRaw_t value)
{
    HAL_StatusTypeDef   status = HAL_OK;
    uint8_t             data[2];


    if (false == config.initialized)
    {
        return WM8804_RC__E_NOT_INITED;
    }

    data[0] = regAddr;
    data[1] = value;

    for (uint8_t i = 0; i < WM8804_I2C__RETRY; i++)
    {
        status = HAL_I2C_Master_Transmit(config.hi2c, config.deviceAddress, data, 2u, WM8804_I2C__TIMEOUT);

        if (HAL_OK == status)
        {
            return WM8804_RC__OK;
        }
    }

    return WM8804_RC__E_HAL;
}

WM8804_Rc WM8804_writeConfig(void)
{
    WM8804_Rc result = WM8804_RC__OK;


    if (false == config.initialized)
    {
        return WM8804_RC__E_NOT_INITED;
    }


    /* Reset WM8804 */
    WM8804_doHardwareReset();


    /* Configuring registers */
    if (WM8804_RC__OK == result)
    {
        /*
         * At the beginning of the configuration, everything is disabled / powered-down.
         */

        WM8804_R30_t reg_pwrdn = {.raw = REG_PWRDN__INIT};
        reg_pwrdn.R.AIFPD = true;           //Disable / Power Down
        reg_pwrdn.R.OSCPD = true;           //Disable / Power Down
        reg_pwrdn.R.PLLPD = true;           //Disable / Power Down
        reg_pwrdn.R.SPDIFRXPD = true;       //Disable / Power Down
        reg_pwrdn.R.SPDIFTXPD = true;       //Disable / Power Down
        reg_pwrdn.R.TRIOP = false;          //Outputs are not tri-stated

        result |= WM8804_writeRegister(REG_PWRDN, reg_pwrdn.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_PLL1__INIT != config.registers.PLL1.raw))
    {
        result |= WM8804_writeRegister(REG_PLL1, config.registers.PLL1.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_PLL2__INIT != config.registers.PLL2.raw))
    {
        result |= WM8804_writeRegister(REG_PLL2, config.registers.PLL2.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_PLL3__INIT != config.registers.PLL3.raw))
    {
        result |= WM8804_writeRegister(REG_PLL3, config.registers.PLL3.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_PLL4__INIT != config.registers.PLL4.raw))
    {
        result |= WM8804_writeRegister(REG_PLL4, config.registers.PLL4.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_PLL5__INIT != config.registers.PLL5.raw))
    {
        result |= WM8804_writeRegister(REG_PLL5, config.registers.PLL5.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_PLL6__INIT != config.registers.PLL6.raw))
    {
        result |= WM8804_writeRegister(REG_PLL6, config.registers.PLL6.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_SPDMODE__INIT != config.registers.SPDMODE.raw))
    {
        result |= WM8804_writeRegister(REG_SPDMODE, config.registers.SPDMODE.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_INTMASK__INIT != config.registers.INTMASK.raw))
    {
        result |= WM8804_writeRegister(REG_INTMASK, config.registers.INTMASK.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_SPDTX1__INIT != config.registers.SPDTX1.raw))
    {
        result |= WM8804_writeRegister(REG_SPDTX1, config.registers.SPDTX1.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_SPDTX2__INIT != config.registers.SPDTX2.raw))
    {
        result |= WM8804_writeRegister(REG_SPDTX2, config.registers.SPDTX2.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_SPDTX3__INIT != config.registers.SPDTX3.raw))
    {
        result |= WM8804_writeRegister(REG_SPDTX3, config.registers.SPDTX3.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_SPDTX4__INIT != config.registers.SPDTX4.raw))
    {
        result |= WM8804_writeRegister(REG_SPDTX4, config.registers.SPDTX4.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_SPDTX5__INIT != config.registers.SPDTX5.raw))
    {
        result |= WM8804_writeRegister(REG_SPDTX5, config.registers.SPDTX5.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_GPO0__INIT != config.registers.GPO0.raw))
    {
        result |= WM8804_writeRegister(REG_GPO0, config.registers.GPO0.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_GPO1__INIT != config.registers.GPO1.raw))
    {
        result |= WM8804_writeRegister(REG_GPO1, config.registers.GPO1.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_GPO2__INIT != config.registers.GPO2.raw))
    {
        result |= WM8804_writeRegister(REG_GPO2, config.registers.GPO2.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_AIFTX__INIT != config.registers.AIFTX.raw))
    {
        result |= WM8804_writeRegister(REG_AIFTX, config.registers.AIFTX.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_AIFRX__INIT != config.registers.AIFRX.raw))
    {
        result |= WM8804_writeRegister(REG_AIFRX, config.registers.AIFRX.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_SPDRX1__INIT != config.registers.SPDRX1.raw))
    {
        result |= WM8804_writeRegister(REG_SPDRX1, config.registers.SPDRX1.raw);
    }

    if ((WM8804_RC__OK == result) && (REG_PWRDN__INIT != config.registers.PWRDN.raw))
    {
        result |= WM8804_writeRegister(REG_PWRDN, config.registers.PWRDN.raw);
    }

    return result;
}
