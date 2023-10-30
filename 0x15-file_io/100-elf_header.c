#include "main.h"

/**
 * print_elf_header - Prints the ELF header information.
 * @header: Pointer to the ELF header structure.
 *
 * Return: Nothing.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class:				%d\n", header->e_ident[EI_CLASS]);
	printf("Data:				%d\n", header->e_ident[EI_DATA]);
	printf("Version:			%d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:				%d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version:			%d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:				%d\n", header->e_type);
	printf("Entry point address:		0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		exit(98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file\n");
		exit(98);
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}

