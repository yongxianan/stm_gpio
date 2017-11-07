/*
 * gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */


/*
uint32_t *gpioGMode = (uint32_t*)(GPIOG_BASE+GPIOG_MODE);
uint32_t *gpioGOSPEED = (uint32_t*)(GPIOG_BASE+GPIOG_OSPEED);
uint32_t *gpioGOPupd = (uint32_t*)(GPIOG_BASE+GPIOG_PUPD);
uint32_t *gpioGOType = (uint32_t*)(GPIOG_BASE+GPIOG_OUT_TYPE);
uint32_t *gpioGOD = (uint32_t*)(GPIOG_BASE+GPIOG_OD);
*/
#include "gpio.h"
/*
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
*/

void gpio_config(gpio_setting *gpio,int pin,int mode, int outDriveType, int pullType, int speed)
{
	gpio->mode_register &=~(3<<(pin*2));
	gpio->mode_register |= mode<<(pin*2);

	gpio->output_type_register &= ~(1<<pin);
	gpio->output_type_register |= outDriveType<<pin;

	gpio->output_speed_register &=~(3<<(pin*2));
	gpio->output_speed_register |= mode<<(pin*2);

	gpio->pull_up_pull_down_register &=~(3<<(pin*2));
	gpio->pull_up_pull_down_register |= mode<<(pin*2);

}

void gpio_bit_set_reset_register(gpio_setting *gpio,int pin,int set_reset)
{
	if(set_reset==1)
	{
		gpio->bit_set_reset_register=(1<<pin);
	}
	else
	{
		gpio->bit_set_reset_register=(1<<16+pin);
	}
}

void gpio_write(gpio_setting *gpio,int pin, int state)
{
	if(state==1)
	{
		gpio->output_data_register |=1<<pin;
	}
	else
	{
		 gpio->output_data_register &= ~(1<<pin);
	}
}


int gpio_read(gpio_setting *gpio,int pin)
{
	return (gpio->input_data_register)&(1<<pin);
}
