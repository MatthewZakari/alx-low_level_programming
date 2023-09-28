#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int x = 1; /* create an unsigned int with value 1 */
	char *c = (char *)&x; /* cast it to a char pointer */

	/* check the value of the first byte */
	if (*c == 1)
	{
		return (1); /* little endian */
	}
	else
	{
		return (0); /* big endian */
	}
}

