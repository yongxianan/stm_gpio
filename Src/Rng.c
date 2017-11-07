/*
 * Rng.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */
#include "Rng.h"
rng_reg *rng;
int enable_random_generator()
{
	return rng->RNG_CR |=1<<2;
}

int isRandomNumberAvailable()
{
	return	rng->RNG_SR & RNG_DRDY;
}

int isAnyError()
{
	return	rng->RNG_SR & (RNG_FAULTY_SEQUENCE | RNG_FAULTY_CLK);
}

int getRandomNumber()
{
	do
	{
		generateRandomNumber();
		while(!isRandomNumberAvailable());

	}while(!isFaultyRandomSeq());
	return rng->RNG_DR;
}

void GetRandomNumberByInterrupt()
{
	rng->RNG_CR |=(RNG_IE | RNG_RNGEN);
}
