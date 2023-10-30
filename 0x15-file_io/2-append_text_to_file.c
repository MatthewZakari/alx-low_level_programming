#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: pointer to the name of the file to append to
 * @text_content: pointer to the string to append to the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	ssize_t bytes_written; /* number of bytes written */
	int len; /* length of the string */

	/* check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* open the file in append mode */
	fd = open(filename, O_WRONLY | O_APPEND);
	/* check if open failed */
	if (fd == -1)
		return (-1);

	/* check if text_content is NULL */
	if (text_content == NULL)
		return (1); /* return 1 because nothing is appended */

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

