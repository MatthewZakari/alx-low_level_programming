#include "main.h"

/**
 * create_file - creates a file and writes a string to it
 * @filename: pointer to the name of the file to create
 * @text_content: pointer to the string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	ssize_t bytes_written; /* number of bytes written */
	int len; /* length of the string */

	/* check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/**
	 * open the file in write-only mode.
	 * create it if it doesn't exist, truncate it if it exists
	 */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	/* check if open failed */
	if (fd == -1)
		return (-1);

	/* check if text_content is NULL */
	if (text_content == NULL)
		return (1); /* return 1 because an empty file is created */

	/* calculate the length of the string */
	len = 0;
	while (text_content[len] != '\0')
		len++;

	/* write the string to the file */
	bytes_written = write(fd, text_content, len);
	/* check if write failed or did not write the expected amount of bytes */
	if (bytes_written == -1 || bytes_written != len)
		return (-1);

	/* close the file descriptor */
	close(fd);
	/* return 1 on success */
	return (1);
}

