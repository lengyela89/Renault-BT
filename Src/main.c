/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */
#include <WM8804.h>
#include <CDCEmulator.h>
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_USART1_UART_Init();

  /* USER CODE BEGIN 2 */
  WM8804_initialize(
		  &hi2c1,
		  0x76u,
		  (WM8804_ResetPinConfig) {
	  	  	  .GPIOPeripheral = WM8804_RESET_GPIO_Port,
	  	  	  .GPIOPin = WM8804_RESET_Pin,
			  .activeLow = false
  	  	  });

  WM8804_registers_t *registers = NULL;
  WM8804_getRegisterConfigs(&registers);

  registers->PLL4.R.TXVAL_OVWR = 0b0;
  registers->PLL4.R.TXVAL_SF1 = 0b0;
  registers->PLL4.R.TXVAL_SF0 = 0b0;
  registers->PLL4.R.PRESCALE = 0b0;
  registers->PLL4.R.PLL_N = 0b1000;

  registers->PLL3.R.PLL_K__21_16 = 0b001100;

  registers->PLL2.R.PLL_K__15_8 = 0b01001001;

  registers->PLL1.R.PLL_K__7_0 = 0b10111010;

  registers->PLL5.R.CLKOUTDIV = 0b11;
  registers->PLL5.R.MCLKDIV = 0b1;
  registers->PLL5.R.FRACEN = 0b1;
  registers->PLL5.R.FREQMODE = 0b10;

  registers->PLL6.R.MCLKSRC = 0b0;
  registers->PLL6.R.ALWAYSVALID = 0b0;
  registers->PLL6.R.FILLMODE = 0b0;
  registers->PLL6.R.CLKOUTDIS = 0b1;
  registers->PLL6.R.CLKOUTSRC = 0b0;

  registers->SPDTX1.R.CHSTMODE = 0b00;				//Channel status mode - ?
  registers->SPDTX1.R.DEEMPH = 0b000;				//Additional Format Information - Data from Audio Interface has no preemphasis - ?
  registers->SPDTX1.R.CPY_N = 0b0;					//Copyright Information - Transmitted data has copyright asserted
  registers->SPDTX1.R.AUDIO_N = 0b0;				//Linear PCM identification - S/PDIF transmitted data is audio PCM
  registers->SPDTX1.R.CON_PRO = 0b0;				//Use of channel status block - Consumer mode

  registers->SPDTX3.R.CHNUM2 = 0b10;				//Send to Right channel
  registers->SPDTX3.R.CHNUM1 = 0b01;				//Send to Left channel
  registers->SPDTX3.R.SRCNUM = 0b0000;				//Source number - ?

  registers->SPDTX4.R.TXSTATSRC = 0b0;
  registers->SPDTX4.R.TXSRC = 0b1;					//Digital Audio Interface Received Data
  registers->SPDTX4.R.CLKACU = 0b11;				//Interface frame rate not matched to sampling frequency
  registers->SPDTX4.R.FREQ = 0b0001;				//Sampling Frequency not indicated

  registers->SPDTX5.R.ORGSAMP = 0b000;				//?
  registers->SPDTX5.R.TXWL = 0b001;					//001 (MAXWL==1 => 20 bits)
  registers->SPDTX5.R.MAXWL = 0b1;					//Maximum Audio Sample Word Length - 24 bits

  registers->AIFRX.R.SYNC_OFF = 0b1;				//?
  registers->AIFRX.R.AIF_MS = 0b1;					//Master mode
  registers->AIFRX.R.AIFRX_LRP = 0b1;				//Invert LRCK polarity
  registers->AIFRX.R.AIFRX_BCP = 0b0;				//BCLK not inverted
  registers->AIFRX.R.AIFRX_WL = 0b01;				//20 bit
  registers->AIFRX.R.AIFRX_FMT = 0b01;				//Left justified mode

  registers->PWRDN.R.TRIOP = 0b0;					//Outputs are not tri-stated
  registers->PWRDN.R.AIFPD = 0b0;					//Digital Audio Interface - Power Up
  registers->PWRDN.R.OSCPD = 0b0;					//Oscillator - Power Up
  registers->PWRDN.R.SPDIFTXPD = 0b0;				//S/PDIF Transmitter - Enabled
  registers->PWRDN.R.SPDIFRXPD = 0b1;				//S/PDIF Receiver - Disabled
  registers->PWRDN.R.PLLPD = 0b0;					//PLL - Enabled

  WM8804_Rc wmRc = WM8804_writeConfig();


  CDCE_Config cdceConfig = {.huart = &huart1};

  CDCE_Rc rc = CDCE_configure(cdceConfig);
  if (CDCE_RC__OK == rc)
  {
	  CDCE_start();
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
	  HAL_GPIO_TogglePin(GPIOC, LED_Pin);
	  HAL_Delay(500u);
  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* I2C1 init function */
static void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* I2C2 init function */
static void MX_I2C2_Init(void)
{

  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_9B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_EVEN;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_Pin|WM8804_RESET_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_Pin WM8804_RESET_Pin */
  GPIO_InitStruct.Pin = LED_Pin|WM8804_RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB14 PB8 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB15 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_15|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
