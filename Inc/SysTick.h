/*
 * SysTick.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

#define SYS_TICK_ADDR	0xE000E010
#define Tick	((SysTickReg *)(SYS_TICK_ADDR))

#define SYSTICK_EN				1
#define	SYSTICK_INTR_EN			(1<<1)
#define	SYSTICK_PROC_CLK_SRC	(1<<2)
#define	SYSTICK_CNTR_OVRFLOW		(1<<16)

typedef struct SysTickReg	SysTickReg;
struct SysTickReg
{
	volatile uint32_t	CTRL;	//control and status register
	volatile uint32_t	LOAD;	//reload value register
	volatile uint32_t	VAL;	//
	volatile uint32_t	CALIB;	//

};

#define sysTickEnable()			(Tick->CTRL |=SYSTICK_EN)
#define sysTickIntrEnable()		(Tick->CTRL |=SYSTICK_INTR_EN)
#define sysTickDisable()		(Tick->CTRL &= ~SYSTICK_EN)
#define sysTickIntrDisable()	(Tick->CTRL &= ~SYSTICK_INTR_EN)
#define sysTickSetReload(x)		(Tick->LOAD = (x))
#define sysTickReadCounter()	(Tick->VAL)
#define sysTickClearCounter()	(Tick->VAL =0xbadface)

#define sysTickFullSpeed()		(Tick->CTRL |=SYSTICK_PROC_CLK_SRC)
#define sysTickPrescaledSpeed()	(Tick->CTRL &= ~SYSTICK_PROC_CLK_SRC)
#define	sysTickHasExpired()		(Tick->CTRL & SYSTICK_CNTR_OVRFLOW)

#endif /* SYSTICK_H_ */
