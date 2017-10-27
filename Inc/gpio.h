/*
 * gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#define GPIOG_BASE			0x40021800
#define GPIOG_MODE			0x00
#define GPIOG_OUT_TYPE		0x04
#define GPIOG_OSPEED		0x08
#define GPIOG_PUPD			0x0c
#define GPIOG_OD			0x14

#define GPIO_MODE_INPUT			0
#define GPIO_OUT_MODE			1
#define GPIO_MODE_AF			2
#define GPIO_MODE_AN			3

#define GPIO_PUSH_PULL			0
#define GPIO_OPEN_DRAIN			1

#define GPIO_LOW_SPEED			0
#define GPIO_MED_SPEED			1
#define GPIO_HI_SPEED			2
#define GPIO_VHI_SPEED			3

#define GPIO_NO_PULL_UP_DOWN	0
#define GPIO_PULL_UP			1
#define GPIO_PULL_DOWN			2
#define GPIO_RESERVE			3

#define redLedPin			14
#define greenLedPin			13
/*
#define GPIOA_BASE			0x40020000
#define GPIOB_BASE			0x40020400
#define GPIOC_BASE			0x40020800
#define GPIOD_BASE			0x40020c00
#define GPIOE_BASE			0x40021000
#define GPIOF_BASE			0x40021400
#define GPIOG_BASE			0x40021800
#define GPIOH_BASE			0x40021c00
#define GPIOI_BASE			0x40022000
*/
#endif /* GPIO_H_ */
