/*
 * LIB_MOTORES.h
 *
 *  Created on: Apr 19, 2026
 *      Author: vlady-HP
 */

#ifndef INC_MOTORES_LIB_H_
#define INC_MOTORES_LIB_H_


#include "stm32f1xx_hal.h"
#include "stdbool.h"

typedef struct{
	int16_t PWM_MR;
	int16_t PWM_ML;
	bool ENABLE;
}Motores_Init;

void Inicializar_Motores(Motores_Init * Mot);
void PWM_Motores(Motores_Init * Mot);

#endif /* INC_MOTORES_LIB_H_ */
