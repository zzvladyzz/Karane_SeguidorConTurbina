/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_Alarma_GPIO_Port, LED_Alarma_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, S0_MUX_Pin|S1_MUX_Pin|S3_MUX_Pin|S2_MUX_Pin
                          |SPI_NSS_Pin|LED_LR_Pin|LED_LL_Pin|MOTOR_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, EN_SENSORES_Pin|LED_RR_Pin|LED_RL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Alarma_Pin */
  GPIO_InitStruct.Pin = LED_Alarma_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_Alarma_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ENCC_MR_Pin */
  GPIO_InitStruct.Pin = ENCC_MR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ENCC_MR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ENCC_ML_Pin */
  GPIO_InitStruct.Pin = ENCC_ML_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ENCC_ML_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : S0_MUX_Pin S1_MUX_Pin S3_MUX_Pin S2_MUX_Pin
                           SPI_NSS_Pin LED_LR_Pin LED_LL_Pin MOTOR_EN_Pin */
  GPIO_InitStruct.Pin = S0_MUX_Pin|S1_MUX_Pin|S3_MUX_Pin|S2_MUX_Pin
                          |SPI_NSS_Pin|LED_LR_Pin|LED_LL_Pin|MOTOR_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : EN_SENSORES_Pin LED_RR_Pin LED_RL_Pin */
  GPIO_InitStruct.Pin = EN_SENSORES_Pin|LED_RR_Pin|LED_RL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
