/*
 * gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

typedef	struct	gpio_setting gpio_setting;
struct gpio_setting
{
	volatile	uint32_t	mode_register;
	volatile	uint32_t	output_type_register;
	volatile	uint32_t	output_speed_register;
	volatile	uint32_t	pull_up_pull_down_register;
	volatile	uint32_t	input_data_register;
	volatile	uint32_t	output_data_register;
	volatile	uint32_t	bit_set_reset_register;
	volatile	uint32_t	configure_lock_register;
	volatile	uint32_t	alternate_function_low_register;
	volatile	uint32_t	alternate_function_high_register;
};




//gpio port
#define	gpio_a	((gpio_setting *)(0x40020000))
#define	gpio_b	((gpio_setting *)(0x40020400))
#define	gpio_c	((gpio_setting *)(0x40020800))
#define	gpio_d	((gpio_setting *)(0x40020C00))
#define	gpio_e	((gpio_setting *)(0x40021000))
#define	gpio_f	((gpio_setting *)(0x40021400))
#define	gpio_g	((gpio_setting *)(0x40021800))
#define	gpio_h	((gpio_setting *)(0x40021C00))
#define	gpio_i	((gpio_setting *)(0x40022000))



//mode
#define GPIO_MODE_IN			0
#define GPIO_OUT_MODE			1
#define GPIO_MODE_AF			2
#define GPIO_MODE_AN			3

//pin output drive type
#define GPIO_PUSH_PULL			0
#define GPIO_OPEN_DRAIN			1

//speed
#define GPIO_LOW_SPEED			0
#define GPIO_MED_SPEED			1
#define GPIO_HI_SPEED			2
#define GPIO_VHI_SPEED			3

//pull type
#define GPIO_NO_PULL_UP_DOWN	0
#define GPIO_PULL_UP			1
#define GPIO_PULL_DOWN			2
#define GPIO_RESERVE			3


#define red_led_pin				14
#define green_led_pin			13

/*
#define GPIOG_BASE			0x40021800
#define GPIOG_MODE			0x00
#define GPIOG_OUT_TYPE		0x04
#define GPIOG_OSPEED		0x08
#define GPIOG_PUPD			0x0c
#define GPIOG_OD			0x14
*/

void gpio_config(gpio_setting * gpio,int pin,int mode, int outDriveType, int pullType, int speed);
void gpio_write(gpio_setting *gpio,int pin, int state);
int gpio_read(gpio_setting *gpio,int pin);
void gpio_bit_set_reset_register(gpio_setting *gpio,int pin,int set_reset);

#endif /* GPIO_H_ */
