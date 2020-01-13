/*
 * WM8804.c
 *
 *  Created on: Feb 1, 2019
 *      Author: lengyela
 */

//TODO add separators

#include "WM8804.h"


typedef struct
{
    I2C_HandleTypeDef       *hi2c;
    WM8804_DeviceAddr       deviceAddress;
    WM8804_ResetPinConfig   resetPinConfig;
    WM8804_registers_t      registers;
    bool                    initialized;
} WM8804_Config;

static WM8804_Config config;



static HAL_StatusTypeDef WM8804_readRegister(WM8804_RegisterAddr regAddr, WM8804_registerRaw_t *data);
static WM8804_Rc WM8804_writeRegister(WM8804_RegisterAddr regAddr, WM8804_registerRaw_t value);



WM8804_Rc WM8804_initialize(I2C_HandleTypeDef *hi2c, WM8804_DeviceAddr deviceAddress, WM8804_ResetPinConfig resetPinConfig)
{
    //TODO check input parameters
    //check resetpinconfig
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

//TODO doc
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

//TODO doc
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

//TODO doc
static HAL_StatusTypeDef WM8804_readRegister(WM8804_RegisterAddr regAddr, WM8804_registerRaw_t *data)
{
    WM8804_Rc status = HAL_OK;


    if (false == config.initialized)
    {
        return WM8804_RC__E_NOT_INITED;
    }

    if (NULL == data)
    {
        return WM8804_RC__E_NULL;
    }

    status |= HAL_I2C_Master_Transmit(config.hi2c, config.deviceAddress, &regAddr, 1u, WM8804_I2C__TIMEOUT);

    status |= HAL_I2C_Master_Receive(config.hi2c, config.deviceAddress, data, 1u, WM8804_I2C__TIMEOUT);

    return (HAL_OK == status ? WM8804_RC__OK : WM8804_RC__E_HAL);
}

//TODO doc
static WM8804_Rc WM8804_writeRegister(WM8804_RegisterAddr regAddr, WM8804_registerRaw_t value)
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

//TODO doc
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
