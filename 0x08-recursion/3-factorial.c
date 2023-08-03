#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number for which you want to calculate the factorial.
 * Return: Always 0
 */

int factorial(int n)
{
	/*Return -1 to indicate an error for negative input*/
	if (n < 0)
	{
		return (-1);
	}

	/*Base case: factorial of 0 is 1*/
	if (n == 0)
	{
		return (1);
	}

	/*Recursive call with n-1 to calculate (n-1)!*/
	return (n * factorial(n - 1));
}
