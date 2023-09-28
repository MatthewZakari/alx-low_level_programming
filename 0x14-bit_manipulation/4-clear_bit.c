#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number to modify
 * @index: the index of the bit, starting from 0
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* check if index is valid */
	if (index > (sizeof(unsigned long int) * 8) - 1)
	{
		return (-1);
	}

	/* create a mask with 0 at the index position and 1 elsewhere */
	mask = ~(1 << index);

	/* set the bit at index to 0 by bitwise AND operation */
	*n = *n & mask;

	/* return 1 if it worked */
	return (1);
}

