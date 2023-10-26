#include "main.h"

/**
 * flip_bits - Calculates the bit difference between two numbers
 * @n: the first number
 * @m: the second number
 * Return: the number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor;
	unsigned int count;

	/* find the XOR of n and m */
	xor = n ^ m;

	/* count the number of set bits in xor */
	count = 0;
	while (xor)
	{
		/* unset the rightmost set bit */
		xor = xor & (xor - 1);
		/* increment the count */
		count++;
	}

	/* return the count */
	return (count);
}
