/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */


#include "Rcc.h"

uint32_t *rccAhb1Rst=(uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1EN=(uint32_t *)(RCC_BASE_ADDR+RCC_AHB1EN_OFF);


void enableGpioA(void)
{
	*rccAhb1Rst &= ~1;
	*rccAhb1EN |=1;
}

void enableGpioG(void)
{
	*rccAhb1EN |=1<<6;
	*rccAhb1Rst &=~(1<<6);
}

void enableGpioC(void)
{
	*rccAhb1EN |=1<<2;
	*rccAhb1Rst &=~(1<<2);
}
