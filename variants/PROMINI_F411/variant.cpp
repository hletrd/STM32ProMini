/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
  PB_9,  //D0
  PB_8,  //D1
  PB_7,  //D2
  PB_6,  //D3
  PB_5,  //D4
  PB_4,  //D5
  PB_3,  //D6
  PA_12, //D7 - USB DP
  PA_11, //D8 - USB DM
  PA_10, //D9
  PA_9,  //D10
  PA_8,  //D11

  PB_15, //D12
  PB_14, //D13
  PB_13, //D14
  PB_12, //D15

  PC_13, //D16
  PA_0,  //D17/A0
  PA_1,  //D18/A1
  PA_2,  //D19/A2
  PA_3,  //D20/A3
  PA_4,  //D21/A4
  PA_5,  //D22/A5
  PA_6,  //D23/A6
  PA_7,  //D24/A7
  PB_0,  //D25/A8
  PB_1,  //D26/A9
  PB_10, //D27

  PB_2,  //D28 - BOOT1
  PA_13, //D29 - SWDI0
  PA_14, //D30 - SWCLK
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  17, //A0
  18, //A1
  19, //A2
  20, //A3
  21, //A4
  22, //A5
  23, //A6
  24, //A7
  25, //A8
  26, //A9
  27, //A10
  28, //A11
  29  //A12
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 10000000
  *            HCLK(Hz)                       = 10000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 400
  *            PLL_P                          = 4
  *            PLL_Q                          = 4
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 3
  * @param  None
  * @retval None
  */

#define HSE_VALUE    ((uint32_t)8000000)

WEAK void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  //RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

  /* Configure the main internal regulator output voltage */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;// | RCC_OSCILLATORTYPE_LSI;
  //RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  //RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  //RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    _Error_Handler(__FILE__, __LINE__);
  }

  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK) {
    _Error_Handler(__FILE__, __LINE__);
  }

  //PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  //PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  //if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
  //  _Error_Handler(__FILE__, __LINE__);
  //}
}
#ifdef __cplusplus
}
#endif
