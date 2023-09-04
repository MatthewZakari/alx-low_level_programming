#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define BUFSIZE 1024

/**
 * error_exit - Print an error message and exit with a specified code.
 * @code: The exit code.
 * @msg: The error message.
 */
void _error(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t r;
	char buffer[BUFSIZE];

	if (argc != 3)
	{
		_error(97, "Usage: cp file_from file_to");
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
        _error(98, "Error: Can't read from file");
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close(file_from);
		_error(99, "Error: Can't write to file");
	}

	while ((r = read(file_from, buffer, BUFSIZE)) > 0)
	{
		if (write(file_to, buffer, r) == -1)
		{
			close(file_from);
			close(file_to);
			_error(99, "Error: Can't write to file");
		}
	}

	if (r == -1)
	{
		close(file_from);
		close(file_to);
        _error(99, "Error: Can't write to file");
	}

	if (close(file_from) == -1 || close(file_to) == -1)
	{
		_error(100, "Error: Can't close fd");
	}

	return (0);
}

