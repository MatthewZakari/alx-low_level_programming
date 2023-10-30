#ifndef MAIN_H
#define MAIN_H

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

#define USAGE_ERROR 97
#define READ_ERROR 98
#define WRITE_ERROR 99
#define CLOSE_ERROR 100

#define USAGE_MSG "Usage: cp file_from file_to\n"
#define READ_MSG "Error: Can't read from file %s\n"
#define WRITE_MSG "Error: Can't write to %s\n"
#define CLOSE_MSG "Error: Can't close fd\n"

/* Function Prototypes */
void error_exit(int code, const char* file, const char* msg);
void print_elf_header(Elf64_Ehdr *header);
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);

#endif


