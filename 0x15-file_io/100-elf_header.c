#include "main.h"

/**
 * check_args - Checks the number of arguments and prints usage if invalid
 * @argc: The number of arguments
 */
void check_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}
}

/**
 * open_and_read_file - Opens the file and reads the ELF header
 * @filename: The name of the file to open
 * @ehdr: Pointer to the ELF header struct
 *
 * Return: The file descriptor of the opened file
 */
int open_and_read_file(char *filename, Elf64_Ehdr *ehdr)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, ehdr, sizeof(*ehdr)) < (ssize_t)sizeof(*ehdr))
	{
		fprintf(stderr, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * print_elf_header - Prints the information in the ELF header
 * @ehdr: Pointer to the ELF header struct
 */
void print_elf_header(Elf64_Ehdr *ehdr)
{
	printf("Magic:   %.2x %.2x %.2x %.2x\n", ehdr->e_ident[EI_MAG0],
			ehdr->e_ident[EI_MAG1], ehdr->e_ident[EI_MAG2], ehdr->e_ident[EI_MAG3]);
	printf("Class:   %s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ?
			"ELF32" : "ELF64");
	printf("Data:    %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d (current)\n", ehdr->e_ident[EI_VERSION]);
	printf("OS/ABI:  UNIX - System V\n");
	printf("ABI Version: %d\n", ehdr->e_ident[EI_ABIVERSION]);
	printf("Type:    %s\n", ehdr->e_type == ET_EXEC ?
			"EXEC (Executable file)" : "Unknown");
	printf("Entry point address:               0x%lx\n", ehdr->e_entry);
}

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: The argument vector
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr ehdr;

	check_args(argc);
	fd = open_and_read_file(argv[1], &ehdr);
	print_elf_header(&ehdr);

	close(fd);
	return (0);
}

