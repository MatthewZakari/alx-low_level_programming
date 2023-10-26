#include "main.h"
#include <stddef.h>
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number, or 0 if b is NULL or contains non-binary chars
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0; /* variable to store the converted number */
	int i = 0; /* variable to loop through the string */

	/* check if b is NULL or empty */
	if (b == NULL || *b == '\0')
		return (0);

	/* loop to iterate through the string */
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}

		num = (num << 1) + (b[i] - '0');
	}

	/* return the converted number */
	return (num);
}

