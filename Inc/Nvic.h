/*
 * Nvic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>
#define	Nvic			((NvicReg *)(0xE000E100))

typedef struct NvicReg	NvicReg;
struct NvicReg
{
	volatile uint32_t	ISER[3];
	volatile uint32_t	reserved_1[29];
	volatile uint32_t	ICER[3];
	volatile uint32_t	reserved_2[29];
	volatile uint32_t	ISPR[3];
	volatile uint32_t	reserved_3[29];
	volatile uint32_t	ICPR[3];
	volatile uint32_t	reserved_4[29];
	volatile uint32_t	IABR[3];
	volatile uint32_t	reserved_5[61];
	volatile uint32_t	IPR[21];
	volatile uint32_t	reserved_6[683];
	volatile uint32_t	STIR[];
};

#define nvicEnableIrq(irqNum)	Nvic->ISER[irqNum>>5] |=1 << (irqNum & 0x1f);
#define nvicDisableIrq(irqNum)	Nvic->ICER[irqNum>>5] |=1 << (irqNum & 0x1f);
#define nvicSetPriorty(irqNum,priorty)	Nvic->IPR[irqNum>>2] |=priorty << ((irqNum & 0x3) * 8 + 4);

#endif /* NVIC_H_ */
