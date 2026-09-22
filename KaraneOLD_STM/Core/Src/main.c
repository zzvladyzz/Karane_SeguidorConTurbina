/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include "MPU6500_LIB.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
MPU6500_Init_Values_t 	MPU6500_Datos; //Iniciamos donde se guardaran todos los datos a leer
MPU6500_status_e	MPU6500_Status;
MPU6500_Init_float_t	MPU6500_Conv;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NumSensores 16

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
char bufferTxt[30];
static uint8_t PosicionesSensores[16]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
volatile uint8_t 	MuxSel=0;
volatile uint16_t 	RegletaSensores[16]={0};
volatile int UltimaPosicion	=500;				// var donde se almacenara la posicion en la linea
volatile unsigned long sumaPonderada = 0;
volatile unsigned long sumaLecturas = 0;
volatile long valor=0;
volatile unsigned long peso=0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Leer_sensores();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

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
  MX_SPI2_Init();
  MX_USART1_UART_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
  MPU6500_Status=MPU6500_Init(&MPU6500_Datos,10,DPS250,G2);
  if (MPU6500_Status==MPU6500_fail) {
  	for (;;) {
  		 sprintf(bufferTxt,"Fallo al iniciar MPU\r\n");
  				  HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);
  				HAL_Delay(500);
  		}
 }
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);

  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,200);
  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,00);
  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,00);
  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,200);
  HAL_GPIO_WritePin(MOTOR_EN_GPIO_Port, MOTOR_EN_Pin, GPIO_PIN_RESET);
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);

  HAL_Delay(2000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {/*
	  MPU6500_Read(&MPU6500_Datos);
	  	  MPU6500_Conv=MPU6500_Converter(&MPU6500_Datos, DPS250_CONV, G2_CONV);

	  	sprintf(bufferTxt," Gx= %.2f ",MPU6500_Conv.MPU6500_floatGX);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

	  	sprintf(bufferTxt," Gy= %.2f ",MPU6500_Conv.MPU6500_floatGY);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

	  	sprintf(bufferTxt," Gz= %.2f ",MPU6500_Conv.MPU6500_floatGZ);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

	  	sprintf(bufferTxt," Ax= %.2f ",MPU6500_Conv.MPU6500_floatAX);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

	  	sprintf(bufferTxt," Ay= %.2f ",MPU6500_Conv.MPU6500_floatAY);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

	  	sprintf(bufferTxt," Az= %.2f \r\n",MPU6500_Conv.MPU6500_floatAZ);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);
	  	HAL_Delay(500);
	  	HAL_GPIO_TogglePin(LED_LL_GPIO_Port, LED_LL_Pin);
	  	HAL_GPIO_TogglePin(LED_LR_GPIO_Port, LED_LR_Pin);
	  	HAL_GPIO_TogglePin(LED_RL_GPIO_Port, LED_RL_Pin);
	  	HAL_GPIO_TogglePin(LED_RR_GPIO_Port, LED_RR_Pin);
	  	HAL_GPIO_TogglePin(LED_Alarma_GPIO_Port, LED_Alarma_Pin);

	  	int16_t encoder_valueA = __HAL_TIM_GET_COUNTER(&htim2);
	  	int16_t encoder_valueB = __HAL_TIM_GET_COUNTER(&htim3);
	  	sprintf(bufferTxt," ENC= %d ",encoder_valueA);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);
	  	sprintf(bufferTxt," ENC= %d ",encoder_valueB);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

	  	HAL_GPIO_WritePin(EN_SENSORES_GPIO_Port, EN_SENSORES_Pin, GPIO_PIN_SET);
	  	HAL_Delay(20);
	  	for(int x=0;x<16;x++)
	  	{
	  	Leer_sensores();
	  	}
	  	sprintf(bufferTxt," posicion %d ",UltimaPosicion);
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);
	  	HAL_GPIO_WritePin(EN_SENSORES_GPIO_Port, EN_SENSORES_Pin, GPIO_PIN_RESET);
 HAL_Delay(300);*/


	  HAL_GPIO_WritePin(EN_SENSORES_GPIO_Port, EN_SENSORES_Pin, 1);
	  //HAL_GPIO_TogglePin(EN_SENSORES_GPIO_Port, EN_SENSORES_Pin);
	  HAL_GPIO_TogglePin(LED_Alarma_GPIO_Port, LED_Alarma_Pin);

	  for (uint8_t var = 0; var < 16; ++var) {


		  HAL_GPIO_WritePin(S0_MUX_GPIO_Port, S0_MUX_Pin, var&1);
		  HAL_GPIO_WritePin(S1_MUX_GPIO_Port, S1_MUX_Pin, (var&2)>>1);
		  HAL_GPIO_WritePin(S2_MUX_GPIO_Port, S2_MUX_Pin, (var&4)>>2);
		  HAL_GPIO_WritePin(S3_MUX_GPIO_Port, S3_MUX_Pin, (var&8)>>3);
		  HAL_Delay(5);
		  Leer_sensores();

	  }


sprintf(bufferTxt,"\r\n ");
	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

	  	    // 4. Detener el ADC
	  	    HAL_ADC_Stop(&hadc1);
HAL_Delay(500);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void Leer_sensores()
{	  HAL_ADC_Start(&hadc1);

  // 2. Esperar a que la conversión termine (Timeout de 10ms)
  if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
  {
      // 3. Obtener el valor (0 a 4095 para 12 bits)
  	uint16_t valor =(uint16_t) HAL_ADC_GetValue(&hadc1); // Lee el resultado

	  sprintf(bufferTxt," A = %d ",valor);
	  	  	HAL_UART_Transmit(&huart1, (uint8_t *)bufferTxt, strlen(bufferTxt), HAL_MAX_DELAY);

  }
	/*
	HAL_ADC_Start(&hadc1);

	    // 2. Esperar a que la conversión termine (Timeout de 10ms)
	    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
	    {
	        // 3. Obtener el valor (0 a 4095 para 12 bits)
	    	RegletaSensores[MuxSel] =(uint16_t) HAL_ADC_GetValue(&hadc1); // Lee el resultado

	    }

	    // 4. Detener el ADC
	    HAL_ADC_Stop(&hadc1);


			if(MuxSel<16)
				{
				valor = RegletaSensores[MuxSel];
				// Se realizara una media ponderada normalizada entre 0-1000 donde 0 es iquierda y 1000 derecha
				// Umbral de ruido: 10% del valor máximo (4095 * 0.1 = 409)
				if (valor > 409) {
					// Peso del sensor (de 0 a 1000)
					peso = (MuxSel * 1000L) / (NumSensores - 1);
					sumaPonderada += peso * valor;
					sumaLecturas += valor;
					}
				MuxSel++;
				}
			else{

							UltimaPosicion = (int)(sumaPonderada / sumaLecturas);
							MuxSel=0;
							sumaLecturas=0;
							sumaPonderada=0;
							peso=0;
							valor=0;
				}
			HAL_GPIO_WritePin(S0_MUX_GPIO_Port, S0_MUX_Pin, (PosicionesSensores[MuxSel]&1));
			HAL_GPIO_WritePin(S1_MUX_GPIO_Port, S1_MUX_Pin, (PosicionesSensores[MuxSel]&2)>>1);
			HAL_GPIO_WritePin(S2_MUX_GPIO_Port, S2_MUX_Pin, (PosicionesSensores[MuxSel]&4)>>2);
			HAL_GPIO_WritePin(S3_MUX_GPIO_Port, S3_MUX_Pin, (PosicionesSensores[MuxSel]&8)>>3);
			HAL_Delay(20);*/
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to repo*t the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
