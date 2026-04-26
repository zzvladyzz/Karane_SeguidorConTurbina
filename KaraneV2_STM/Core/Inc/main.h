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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define AMP_ML_Pin GPIO_PIN_0
#define AMP_ML_GPIO_Port GPIOC
#define AMP_MR_Pin GPIO_PIN_1
#define AMP_MR_GPIO_Port GPIOC
#define VOLT_BATT_Pin GPIO_PIN_2
#define VOLT_BATT_GPIO_Port GPIOC
#define IN_MUX_Pin GPIO_PIN_3
#define IN_MUX_GPIO_Port GPIOC
#define Encoder_A_ML_Pin GPIO_PIN_0
#define Encoder_A_ML_GPIO_Port GPIOA
#define Encoder_B_ML_Pin GPIO_PIN_1
#define Encoder_B_ML_GPIO_Port GPIOA
#define Encoder_C_ML_Pin GPIO_PIN_2
#define Encoder_C_ML_GPIO_Port GPIOA
#define Encoder_A_MR_Pin GPIO_PIN_5
#define Encoder_A_MR_GPIO_Port GPIOA
#define S0_MUX_Pin GPIO_PIN_4
#define S0_MUX_GPIO_Port GPIOC
#define S1_MUX_Pin GPIO_PIN_5
#define S1_MUX_GPIO_Port GPIOC
#define S2_MUX_Pin GPIO_PIN_0
#define S2_MUX_GPIO_Port GPIOB
#define S3_MUX_Pin GPIO_PIN_1
#define S3_MUX_GPIO_Port GPIOB
#define BOTON_START_Pin GPIO_PIN_2
#define BOTON_START_GPIO_Port GPIOB
#define BOTON_STOP_Pin GPIO_PIN_10
#define BOTON_STOP_GPIO_Port GPIOB
#define LED_4_Pin GPIO_PIN_12
#define LED_4_GPIO_Port GPIOB
#define LED_3_Pin GPIO_PIN_13
#define LED_3_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_14
#define LED_2_GPIO_Port GPIOB
#define LED_1_Pin GPIO_PIN_15
#define LED_1_GPIO_Port GPIOB
#define LED_ALARMA_Pin GPIO_PIN_8
#define LED_ALARMA_GPIO_Port GPIOC
#define LED_OK_Pin GPIO_PIN_9
#define LED_OK_GPIO_Port GPIOC
#define PWM_FAN_Pin GPIO_PIN_8
#define PWM_FAN_GPIO_Port GPIOA
#define PWM_RED_Pin GPIO_PIN_9
#define PWM_RED_GPIO_Port GPIOA
#define PWM_GREEN_Pin GPIO_PIN_10
#define PWM_GREEN_GPIO_Port GPIOA
#define PWM_BLUE_Pin GPIO_PIN_11
#define PWM_BLUE_GPIO_Port GPIOA
#define IR_36KHZ_Pin GPIO_PIN_12
#define IR_36KHZ_GPIO_Port GPIOA
#define SPI3_NSS_Pin GPIO_PIN_15
#define SPI3_NSS_GPIO_Port GPIOA
#define Encoder_C_MR_Pin GPIO_PIN_2
#define Encoder_C_MR_GPIO_Port GPIOD
#define Encoder_B_MR_Pin GPIO_PIN_3
#define Encoder_B_MR_GPIO_Port GPIOB
#define EN_SENSORES_Pin GPIO_PIN_4
#define EN_SENSORES_GPIO_Port GPIOB
#define EN_MOTOR_Pin GPIO_PIN_5
#define EN_MOTOR_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
