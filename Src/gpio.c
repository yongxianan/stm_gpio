/*
 * gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include"gpio.h"
uint32_t *gpioGMode = (uint32_t*)(GPIOG_BASE+GPIOG_MODE);
uint32_t *gpioGOSPEED = (uint32_t*)(GPIOG_BASE+GPIOG_OSPEED);
uint32_t *gpioGOPupd = (uint32_t*)(GPIOG_BASE+GPIOG_PUPD);
uint32_t *gpioGOType = (uint32_t*)(GPIOG_BASE+GPIOG_OUT_TYPE);
uint32_t *gpioGOD = (uint32_t*)(GPIOG_BASE+GPIOG_OD);

void gpioGConfig(int pin,int mode, int outDriveType, int pullType, int speed)
{
	*gpioGMode &= ~(3<<(pin*2));	//clear pin mode to zero
	*gpioGMode |= mode<<(pin*2);

	*gpioGOSPEED &= ~(3<<(pin*2));
	*gpioGOSPEED |= speed<<(pin*2);

	*gpioGOSPEED &= ~(3<<(pin*2));
	*gpioGOPupd |= pullType<<(pin*2);

	*gpioGOType &= ~(1<<pin);
	*gpioGOType |= outDriveType<<pin;
}

void gpioGWrite(int pin, int state)
{
	if(state==1)
	{
		*gpioGOD |=1<<pin;
	}
	else
	{
		*gpioGOD &= ~(1<<pin);
	}
}
