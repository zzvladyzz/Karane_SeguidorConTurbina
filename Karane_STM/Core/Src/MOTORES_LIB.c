#include "MOTORES_LIB.h"
#include "tim.h"
#include "gpio.h"
#define PWM_Timer		htim4
#define PWM_ML_A		TIM_CHANNEL_3
#define PWM_ML_B		TIM_CHANNEL_4

#define PWM_MR_B		TIM_CHANNEL_1
#define PWM_MR_A		TIM_CHANNEL_2

#define Enable_PORT		GPIOB
#define Enable_PIN		GPIO_PIN_5

#define PWM_MAX			999

void Inicializar_Motores(Motores_Init * Mot)
{
	HAL_GPIO_WritePin(Enable_PORT, Enable_PIN, GPIO_PIN_RESET);
	HAL_TIM_PWM_Start(&PWM_Timer, PWM_ML_A);
	HAL_TIM_PWM_Start(&PWM_Timer, PWM_ML_B);
	HAL_TIM_PWM_Start(&PWM_Timer, PWM_MR_B);
	HAL_TIM_PWM_Start(&PWM_Timer, PWM_MR_A);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_A,0);
	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_B,0);
	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_B,0);
	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_A,0);
	Mot->ENABLE=false;
	Mot->PWM_ML=0;
	Mot->PWM_MR=0;

}
void PWM_Motores(Motores_Init * Mot)
{
	HAL_GPIO_WritePin(Enable_PORT, Enable_PIN, Mot->ENABLE);
	int16_t PWM_ML=0;
	int16_t PWM_MR=0;


	if((Mot->PWM_ML)<0)
	{
		Mot->PWM_ML=((Mot->PWM_ML)<-PWM_MAX)?-PWM_MAX:Mot->PWM_ML;

		PWM_ML=999+Mot->PWM_ML;
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_A,999);
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_B,PWM_ML);

	}
	else
	{
		Mot->PWM_ML=((Mot->PWM_ML)>PWM_MAX)?PWM_MAX:Mot->PWM_ML;

		PWM_ML=999-Mot->PWM_ML;
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_A,PWM_ML);
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_B,999);
	}



	if((Mot->PWM_MR)<0)
	{
		Mot->PWM_MR=((Mot->PWM_MR)<-PWM_MAX)?-PWM_MAX:Mot->PWM_MR;

		PWM_MR=999+Mot->PWM_MR;
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_A,999);
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_B,PWM_ML);
	}
	else
	{
		Mot->PWM_MR=((Mot->PWM_MR)>PWM_MAX)?PWM_MAX:Mot->PWM_MR;

		PWM_MR=999-Mot->PWM_MR;
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_A,PWM_MR);
		__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_B,999);
	}
/*

	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_A,150);
	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_ML_B,0);
	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_B,0);
	__HAL_TIM_SET_COMPARE(&PWM_Timer,PWM_MR_A,100);*/

}


