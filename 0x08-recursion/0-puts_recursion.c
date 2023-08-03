#include "main.h"

/**
 * _puts_recursion -  prints a string, followed by a new line
 * @s: is the string we're printing
 * Return: Always 0
 */

void _puts_recursion(char *s)
{
	/*Base case: When we reach the end of the string (null terminator)*/
	if (*s == '\0')
	{
		_putchar('\n');  /*Print a new line character*/
		return;          /*Exit the function*/
	}
	_putchar(*s);    /*Print the current character*/
	_puts_recursion(s + 1);
	/*Call the function with the next character in the string*/
}
