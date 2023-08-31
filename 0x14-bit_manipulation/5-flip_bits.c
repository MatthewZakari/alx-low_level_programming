#include <stdio.h>
#include "main.h"

/**
 * flip_bits - Calculates bit-flip count between numbers.
 * @n: First number
 * @m: Second number
 *
 * Return: Number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int _numb = 0;

	while (xor_result > 0)
	{
		_numb += xor_result & 1;
		xor_result >>= 1;
	}

	return (_numb);
}

