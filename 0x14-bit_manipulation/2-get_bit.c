#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the number to get the bit from
 * @index: the index of the bit, starting from 0
 * Return: the value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* check if index is valid */
	if (index > (sizeof(unsigned long int) * 8) - 1)
	{
		return (-1);
	}

	/* right shift n by index bits and mask the rightmost bit */
	return ((n >> index) & 1);
}

