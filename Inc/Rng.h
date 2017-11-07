/*
 * Rng.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef RNG_H_
#define RNG_H_
#include <stdio.h>


typedef	struct	rng_reg rng_reg;
struct rng_reg
{
	volatile	uint32_t	RNG_CR;
	volatile	uint32_t	RNG_SR;
	volatile	uint32_t	RNG_DR;
};



#define	RNG_FAULTY_SEQUENCE	(1<<2)
#define	RNG_FAULTY_CLK		(1<<1)
#define	RNG_DRDY			(1)

#define	RNG_RNGEN			(1<<2)
#define RNG_IE				(1<<3)

#endif /* RNG_H_ */
