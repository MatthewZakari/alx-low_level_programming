#ifndef MAIN_H
#define MAIN_H

#define _POSIX_C_SOURCE 200809L
#define BUFFER_SIZE 1024
#define USAGE_ERROR 97
#define READ_ERROR 98
#define WRITE_ERROR 99
#define CLOSE_ERROR 100

#define USAGE_MSG "Usage: cp file_from file_to\n"
#define READ_MSG "Error: Can't read from file %s\n"
#define WRITE_MSG "Error: Can't write to %s\n"
#define CLOSE_MSG "Error: Can't close fd %d\n"


#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void error_exit(int code, char *file, char *msg);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
