#include "main.h"
#include <stddef.h>


/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: The binary string to convert.
 *
 * Return: The converted unsigned int, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (*b)
	{
		if (*b == '0')
		{
			result <<= 1; /* Left-shift result by 1 (multiply by 2) */
		}
		else if (*b == '1')
		{
			result <<= 1; /* Left-shift result by 1 (multiply by 2) */
			result |= 1;  /* Set the LSB to 1 */
		}
		else
		{
			return (0); /* Invalid character in the binary string */
		}
		b++;
	}

	return (result);
}

