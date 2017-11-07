/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_BASE_ADDR	0x40023800
#define RCC_AHB1RST_OFF	0x10
#define RCC_AHB1EN_OFF	0x30

typedef	struct	RCC_REG RCC_REG;
struct RCC_REG
{
	volatile	uint32_t	RCC_CR;
	volatile	uint32_t	RCC_PLLCFGR;
	volatile	uint32_t	RCC_CFGR;
	volatile	uint32_t	RCC_CIR;
	volatile	uint32_t	RCC_AHB1RSTR;
	volatile	uint32_t	RCC_AHB2RSTR;
	volatile	uint32_t	RCC_AHB3RSTR;
	volatile	uint32_t	RESERVED_1;
	volatile	uint32_t	RCC_APB1RSTR;
	volatile	uint32_t	RCC_APB2RSTR;
	volatile	uint32_t	RESERVED_2;
	volatile	uint32_t	RESERVED_3;
	volatile	uint32_t	RCC_AHB1ENR;
	volatile	uint32_t	RCC_AHB2ENR;
	volatile	uint32_t	RCC_AHB3ENR;
	volatile	uint32_t	RESERVED_4;
	volatile	uint32_t	RCC_APB1ENR;
	volatile	uint32_t	RCC_APB2ENR;
	volatile	uint32_t	RESERVED_5;
	volatile	uint32_t	RESERVED_6;
	volatile	uint32_t	RCC_AHB1LPENR;
	volatile	uint32_t	RCC_AHB2LPENR;
	volatile	uint32_t	RCC_AHB3LPENR;
	volatile	uint32_t	RESERVED_7;
	volatile	uint32_t	RCC_APB1LPENR;
	volatile	uint32_t	RCC_APB2LPENR;
	volatile	uint32_t	RESERVED_8;
	volatile	uint32_t	RESERVED_9;
	volatile	uint32_t	RCC_BDCR;
	volatile	uint32_t	RCC_CSR;
	volatile	uint32_t	RESERVED_10;
	volatile	uint32_t	RESERVED_11;
	volatile	uint32_t	RCC_SSCGR;
	volatile	uint32_t	RCC_PLLI2SCFGR;


};

void enableGpioA(void);
void enableGpioG(void);
#endif /* RCC_H_ */
