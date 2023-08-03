#include "main.h"
/**
 * _print_rev_recursion -  prints a string in reverse.
 * @s: string we're printing in reverse
 * Return: Always 0
 */

void _print_rev_recursion(char *s)
{
	/*Base case: When we reach the end of the string (null terminator)*/
	if (*s == '\0')
	{
		return;
	}

	/*Recursive call with the next character in the string*/
	_print_rev_recursion(s + 1);
	/* Print the current character after the recursive call returns*/
	_putchar(*s);
}
