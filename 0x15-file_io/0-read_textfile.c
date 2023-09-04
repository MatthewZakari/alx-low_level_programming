#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * read_textfile - Reads and prints a text file to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t bytes_r, bytes_w;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	bytes_r = read(file_descriptor, buffer, letters);
	if (bytes_r == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	bytes_w = write(STDOUT_FILENO, buffer, bytes_r);
	if (bytes_w == -1 || bytes_w != bytes_r)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	free(buffer);
	close(file_descriptor);
	return (bytes_w);
}

