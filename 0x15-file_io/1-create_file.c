#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - Creates a file and writes text content to it
 * @filename: The name of the file to create
 * @text_content: The text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, w_result, text_length = 0;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[text_length] != '\0')
		{
			text_length++;

		w_result = write(file_descriptor, text_content, text_length);
		if (w_result == -1)
			return (-1);
		}
	}

	close(file_descriptor);
	return (1);
}

