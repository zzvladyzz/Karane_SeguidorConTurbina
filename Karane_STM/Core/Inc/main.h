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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Alarma_Pin GPIO_PIN_13
#define LED_Alarma_GPIO_Port GPIOC
#define PULSADOR_Pin GPIO_PIN_14
#define PULSADOR_GPIO_Port GPIOC
#define ENCC_MR_Pin GPIO_PIN_15
#define ENCC_MR_GPIO_Port GPIOC
#define MR_Pin GPIO_PIN_2
#define MR_GPIO_Port GPIOA
#define ENCC_ML_Pin GPIO_PIN_0
#define ENCC_ML_GPIO_Port GPIOB
#define S0_MUX_Pin GPIO_PIN_1
#define S0_MUX_GPIO_Port GPIOB
#define S1_MUX_Pin GPIO_PIN_2
#define S1_MUX_GPIO_Port GPIOB
#define S3_MUX_Pin GPIO_PIN_10
#define S3_MUX_GPIO_Port GPIOB
#define S2_MUX_Pin GPIO_PIN_11
#define S2_MUX_GPIO_Port GPIOB
#define SPI_NSS_Pin GPIO_PIN_12
#define SPI_NSS_GPIO_Port GPIOB
#define PWM_FAN_Pin GPIO_PIN_8
#define PWM_FAN_GPIO_Port GPIOA
#define EN_SENSORES_Pin GPIO_PIN_11
#define EN_SENSORES_GPIO_Port GPIOA
#define LED_D_Pin GPIO_PIN_12
#define LED_D_GPIO_Port GPIOA
#define LED_C_Pin GPIO_PIN_15
#define LED_C_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_3
#define LED_B_GPIO_Port GPIOB
#define LED_A_Pin GPIO_PIN_4
#define LED_A_GPIO_Port GPIOB
#define MOTOR_EN_Pin GPIO_PIN_5
#define MOTOR_EN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
