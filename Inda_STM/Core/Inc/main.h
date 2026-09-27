/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_OK_Pin GPIO_PIN_13
#define LED_OK_GPIO_Port GPIOC
#define LED_ALARMA_Pin GPIO_PIN_14
#define LED_ALARMA_GPIO_Port GPIOC
#define LED_AVISO_Pin GPIO_PIN_15
#define LED_AVISO_GPIO_Port GPIOC
#define OUT_MUX_Pin GPIO_PIN_0
#define OUT_MUX_GPIO_Port GPIOC
#define VOLTAGE_BATT_Pin GPIO_PIN_3
#define VOLTAGE_BATT_GPIO_Port GPIOC
#define ENCA_MR_Pin GPIO_PIN_0
#define ENCA_MR_GPIO_Port GPIOA
#define ENCB_MR_Pin GPIO_PIN_1
#define ENCB_MR_GPIO_Port GPIOA
#define ENCZ_MR_Pin GPIO_PIN_2
#define ENCZ_MR_GPIO_Port GPIOA
#define IN_IR_MR_Pin GPIO_PIN_3
#define IN_IR_MR_GPIO_Port GPIOA
#define LED_MR_LINEA_Pin GPIO_PIN_4
#define LED_MR_LINEA_GPIO_Port GPIOA
#define ENCA_ML_Pin GPIO_PIN_5
#define ENCA_ML_GPIO_Port GPIOA
#define PWM_BLUE_Pin GPIO_PIN_6
#define PWM_BLUE_GPIO_Port GPIOA
#define PWM_GREEN_Pin GPIO_PIN_7
#define PWM_GREEN_GPIO_Port GPIOA
#define BUTTON_START_Pin GPIO_PIN_4
#define BUTTON_START_GPIO_Port GPIOC
#define BUTTON_STOP_Pin GPIO_PIN_5
#define BUTTON_STOP_GPIO_Port GPIOC
#define PWM_RED_Pin GPIO_PIN_0
#define PWM_RED_GPIO_Port GPIOB
#define LED6_Pin GPIO_PIN_1
#define LED6_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_2
#define LED5_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_10
#define LED4_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_11
#define LED3_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_12
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOB
#define PWM_8052B_Pin GPIO_PIN_14
#define PWM_8052B_GPIO_Port GPIOB
#define PWM_8052A_Pin GPIO_PIN_15
#define PWM_8052A_GPIO_Port GPIOB
#define EN_SENSORES_Pin GPIO_PIN_6
#define EN_SENSORES_GPIO_Port GPIOC
#define S0_MUX_Pin GPIO_PIN_7
#define S0_MUX_GPIO_Port GPIOC
#define S1_MUX_Pin GPIO_PIN_8
#define S1_MUX_GPIO_Port GPIOC
#define S3_MUX_Pin GPIO_PIN_9
#define S3_MUX_GPIO_Port GPIOC
#define S2_MUX_Pin GPIO_PIN_8
#define S2_MUX_GPIO_Port GPIOA
#define IN_IR_ML_Pin GPIO_PIN_11
#define IN_IR_ML_GPIO_Port GPIOA
#define IR_36KHZ_Pin GPIO_PIN_12
#define IR_36KHZ_GPIO_Port GPIOA
#define SPI_NSS_Pin GPIO_PIN_15
#define SPI_NSS_GPIO_Port GPIOA
#define LED_ML_LINEA_Pin GPIO_PIN_2
#define LED_ML_LINEA_GPIO_Port GPIOD
#define ENCB_ML_Pin GPIO_PIN_3
#define ENCB_ML_GPIO_Port GPIOB
#define ENCZ_ML_Pin GPIO_PIN_4
#define ENCZ_ML_GPIO_Port GPIOB
#define MOTOR_EN_Pin GPIO_PIN_5
#define MOTOR_EN_GPIO_Port GPIOB
#define PWMA_ML_Pin GPIO_PIN_6
#define PWMA_ML_GPIO_Port GPIOB
#define PWMB_ML_Pin GPIO_PIN_7
#define PWMB_ML_GPIO_Port GPIOB
#define PWMB_MR_Pin GPIO_PIN_8
#define PWMB_MR_GPIO_Port GPIOB
#define PWMA_MR_Pin GPIO_PIN_9
#define PWMA_MR_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
