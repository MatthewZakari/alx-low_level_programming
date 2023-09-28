#include <stdio.h>
#include <string.h>
#include "main.h"

/* define the correct password as a constant string */
#define PASSWORD "1234"

/**
 * main - asks for a password and checks if it is correct
 * Return: 0 if successful, 1 if an error occurred
 */
int main(void)
{
	/* declare a char array to store the input password */
	char input[20];

	/* prompt the user to enter the password */
	printf("Enter the password: ");

	/* read the input from stdin and store it in input */
	if (scanf("%s", input) != 1)
	{
		/* print an error message if scanf failed */
		printf("Error reading input\n");
		return (1);
	}

	/* compare the input with the correct password using strcmp */
	if (strcmp(input, PASSWORD) == 0)
	{
		/* print a success message if they match */
		printf("Correct password\n");
	}
	else
	{
		/* print a failure message if they don't match */
		printf("Incorrect password\n");
	}

	/* return 0 to indicate success */
	return (0);
}

