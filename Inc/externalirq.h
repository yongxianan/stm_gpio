/*
 * externalirq.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef EXTERNALIRQ_H_
#define EXTERNALIRQ_H_

#include <stdint.h>
#define EXTERNALIRQ_BASE_ADDR	0x40013c00
typedef struct EXTIReg EXTIReg
struct EXTIReg
{
	volatile uint32_t IMR;		//interrupt mask register
	volatile uint32_t EMR;		//event mask register
	volatile uint32_t RTSR;		//rising trigger selection register
	volatile uint32_t FTSR;		//falling trigger selection register
	volatile uint32_t SWIER;	//software interrupt event register
	volatile uint32_t PR;		//pending register
};

#define Exti	((EXTIReg *)(EXTERNALIRQ_BASE_ADDR))
#define	EXTI_IMR_enable(x)						(Exti->IMR |=(1<<(x)))
#define	EXTI_IMR_disable(x)						(Exti->IMR &=~(1<<(x)))
#define	EXTI_EMR_MASK(x)						(Exti->EMR |=(1<<(x)))
#define	EXTI_EMR_UNMASK(x)						(Exti->EMR &=~(1<<(x)))
#define	EXTI_RTSR_set_rising_trigger(x)			(Exti->RTSR |=(1<<(x)))
#define	EXTI_RTSR_reset_rising_trigger(x)		(Exti->RTSR &=~(1<<(x)))
#define	EXTI_FTSR_set_falling_trigger(x)		(Exti->FTSR |=(1<<(x)))
#define	EXTI_FTSR_reset_falling_trigger(x)		(Exti->FTSR &=~(1<<(x)))
#define	EXTI_SWIER_set_software_trigger(x)		(Exti->SWIER |=(1<<(x)))
#define	EXTI_PR_pending_clear(x)				(Exti->PR |=(1<<(x)))

#endif /* EXTERNALIRQ_H_ */
