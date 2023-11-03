#include "main.h"
/**
 * copyFile - copies the content of a file to another file
 * @src_filename: source file name
 * @dest_filename: destination file name
 * Return: 0 on success, exit with code on failure
 */
int copyFile(const char *src_filename, const char *dest_filename)
{
	int src_fd, dest_fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	src_fd = open(src_filename, O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_filename);
		return (98);
	}
	dest_fd = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", dest_filename);
		close(src_fd);
		return (99);
	}
	do {
		bytes_read = read(src_fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_filename);
			close(src_fd);
			close(dest_fd);
			return (98);
		}
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", dest_filename);
			close(src_fd);
			close(dest_fd);
			return (99);
		}
	} while (bytes_read > 0);
	if (close(src_fd) == -1 || close(dest_fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
	return (100);
	return (0);
}

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char *argv[])
{
	int result = copyFile(argv[1], argv[2]);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}
	return (result);
}

