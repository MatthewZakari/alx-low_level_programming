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

	/* loop through the string until the end */
	while (b[i] != '\0')
	{
		/* check if the current char is 0 or 1 */
		if (b[i] == '0' || b[i] == '1')
		{
			/* left shift the previous number by one bit */
			num = num << 1;
			/* add the current bit to the number */
			num = num + (b[i] - '0');
		}
		else
		{
			/* return 0 if the current char is not 0 or 1 */
			return (0);
		}
		/* increment the index */
		i++;
	}

	/* return the converted number */
	return (num);
}

