#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer to the name of the file to read
 * @letters: number of letters to read and print
 * Return: actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd; /* file descriptor */
	char *buffer; /* buffer to store the data */
	ssize_t bytes_read; /* number of bytes read */
	ssize_t bytes_written; /* number of bytes written */

	/* check if filename is NULL */
	if (filename == NULL)
		return (0);

	/* open the file in read-only mode */
	fd = open(filename, O_RDONLY);
	/* check if open failed */
	if (fd == -1)
		return (0);

	/* allocate memory for the buffer */
	buffer = malloc(sizeof(char) * letters);
	/* check if malloc failed */
	if (buffer == NULL)
		return (0);

	/* read up to letters bytes from the file into the buffer */
	bytes_read = read(fd, buffer, letters);
	/* check if read failed */
	if (bytes_read == -1)
		return (0);

	/* write the data from the buffer to the standard output */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	/* check if write failed or did not write the expected amount of bytes */
	if (bytes_written == -1 || bytes_written != bytes_read)
		return (0);

	/* free the buffer */
	free(buffer);
	/* close the file descriptor */
	close(fd);
	/* return the actual number of letters read and printed */
	return (bytes_read);
}

