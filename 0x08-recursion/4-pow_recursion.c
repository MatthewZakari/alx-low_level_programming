#include "main.h"

/**
 * _pow_recursion -  returns the value of x raised to the power of y
 * @x: represents the base value
 * @y: represents the exponent value.
 * Return: Always 0
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1); /*Return -1 to indicate an error for negative exponent*/
	}
	if (y == 0)
	{
		return (1); /*Base case: Any number raised to the power of 0 is 1*/
	}

	return (x * _pow_recursion(x, y - 1)); /*Recursive call to calculate x^y*/
}
