#include <stdint.h>
#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */

int get_endianness(void)
{
	uint32_t numb = 1; /* A 4-byte integer with the value 1 */
	uint8_t *byte_ptr = (uint8_t *)&numb;

	/* If the least significant byte is 1, it's little-endian. */
	/* If the most significant byte is 1, it's big-endian. */
	/* Otherwise, it's an unknown endianness. */
	if (*byte_ptr == 1)
	{
		return (1); /* Little-endian */
	}
	else if (*(byte_ptr + 3) == 1)
	{
		return (0);  /* Big-endian */
	}
	else
	{
		/* Indeterminate endianness or some other architecture */
		return (-1);
	}
}

