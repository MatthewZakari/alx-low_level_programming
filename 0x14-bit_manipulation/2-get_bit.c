#include "main.h"

/**
 * get_bit - Get the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to get (0-based).
 *
 * Return: The value at the specified index, or -1 if an error occurs.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1); /* Index out of bounds */
	}

	return ((n >> index) & 1);
}

