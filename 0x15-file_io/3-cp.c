#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char *argv[])
{
	int i, fd[2]; /* file descriptors */
	char buffer[BUFFER_SIZE]; /* buffer to store the data */
	ssize_t bytes_read, bytes_written; /* num of bytes read and written */
	/* char *error_file;  name of the file that caused the error */

	/* check if the number of arguments is correct */
	if (argc != 3)
		error_exit(USAGE_ERROR, NULL, USAGE_MSG);

	/* open the source file in read-only mode */
	fd[0] = open(argv[1], O_RDONLY);
	/* check if open failed */
	if (fd[0] == -1)
		error_exit(READ_ERROR, argv[1], READ_MSG);

	fd[1] = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	/* check if open failed */
	if (fd[1] == -1)
		error_exit(WRITE_ERROR, argv[2], WRITE_MSG);

	/* read and write until EOF or error */
	do {
		/* read up to BUFFER_SIZE bytes from the source file into the buffer */
		bytes_read = read(fd[0], buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			error_exit(READ_ERROR, argv[1], READ_MSG);

		/* write the data from the buffer to the destination file */
		bytes_written = write(fd[1], buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			error_exit(WRITE_ERROR, argv[2], WRITE_MSG);
	} while (bytes_read > 0);

	/* close both file descriptors */
	for (i = 0; i < 2; i++)
	{
		if (close(fd[i]) == -1)
			error_exit(CLOSE_ERROR, NULL, CLOSE_MSG);
	}
	return (0);
}

/**
 * error_exit - prints an error message and exits with a code
 * @code: exit code
 * @file: name of the file that caused the error
 * @msg: error message format
 */
void error_exit(int code, char *file, char *msg)
{
	dprintf(STDERR_FILENO, msg, file);
	exit(code);
}

