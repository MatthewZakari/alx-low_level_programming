#include <stdio.h>

/**
 * add - add two intergers
 * @a: first int 
 * @b: second int
 * Return: addition
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtract two integers
 * @a: first int
 * @b: second int
 * Return: subtraction
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiply two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: product of a and b
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - divide two integers
 * @a: dividend
 * @b: divisor
 *
 * Return: result of division of a by b
 */
int div(int a, int b)
{
	return (a / b);
}

/**
 * mod - calculate the modulus of two integers
 * @a: dividend
 * @b: divisor
 *
 * Return: remainder of the division of a by b
 */
int mod(int a, int b)
{
	return (a % b);
}
