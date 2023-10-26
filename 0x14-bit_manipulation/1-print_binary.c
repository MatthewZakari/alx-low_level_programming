 #include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 */
void print_binary(unsigned long int n)
{
	/* if n is zero, print 0 */
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	/* if n is one, print 1 */
	if (n == 1)
	{
		_putchar('1');
		return;
	}

	/* recursively print the rightmost bit and left shift n by one bit */
	print_binary(n >> 1);
	_putchar((n & 1) + '0');
}

