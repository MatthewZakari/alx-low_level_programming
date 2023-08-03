#include "main.h"
/**
 * _strlen_recursion - returns the length of a string
 * @s: represents the string whose length we're calculating
 * Return: Always 0
 */

int _strlen_recursion(char *s)
{
	/*Base case: When we reach the end of the string (null terminator)*/
	if (*s == '\0')
	{
		return (0);
	}

	/*Recursive call with the next character in the string*/
	return (1 + _strlen_recursion(s + 1));
}
