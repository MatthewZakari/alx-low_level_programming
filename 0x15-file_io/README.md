# File I/O Functions

This directory contains C programs and functions related to file input/output operations.

## Contents

0. [read_textfile](#read_textfile)
1. [create_file](#create_file)
2. [append_text_to_file](#append_text_to_file)
3. [cp](#cp)
4. [elf_header](#elf_header) (Advanced)



0. read_textfile

### Description

This function reads a text file and prints it to the POSIX standard output.

### Prototype
ssize_t read_textfile(const char *filename, size_t letters);

- `filename`: The name of the file to read.
- `letters`: The number of letters to read and print.

### Returns

- The actual number of letters it could read and print.
- If the file cannot be opened or read, it returns `0`.
- If `filename` is `NULL`, it returns `0`.
- If `write` fails or does not write the expected amount of bytes, it returns `0`.

1. create_file

### Description

This function creates a file.

### Prototype
int create_file(const char *filename, char *text_content);

- `filename`: The name of the file to create.
- `text_content`: A NULL-terminated string to write to the file.

### Returns

- `1` on success.
- `-1` on failure (file cannot be created, written, etc.).
- The created file has permissions `rw-------`.
- If the file already exists, it is truncated.
- If `filename` is `NULL`, it returns `-1`.
- If `text_content` is `NULL`, it creates an empty file.


2. append_text_to_file

### Description

This function appends text at the end of a file.

### Prototype
int append_text_to_file(const char *filename, char *text_content);

- `filename`: The name of the file.
- `text_content`: A NULL-terminated string to add at the end of the file.

### Returns

- `1` on success.
- `-1` on failure.
- Does not create the file if it does not exist.
- If `filename` is `NULL`, it returns `-1`.
- If `text_content` is `NULL`, it does not add anything to the file.


3. cp

### Description

This program copies the content of one file to another file.

### Usage


cp file_from file_to


- If the number of arguments is incorrect, it exits with code `97` and prints `Usage: cp file_from file_to` to STDERR.
- If `file_to` already exists, it truncates it.
- If `file_from` does not exist or cannot be read, it exits with code `98` and prints `Error: Can't read from file NAME_OF_THE_FILE` to STDERR.
- If it cannot create or if write to `file_to` fails, it exits with code `99` and prints `Error: Can't write to NAME_OF_THE_FILE` to STDERR.
- If it cannot close a file descriptor, it exits with code `100` and prints `Error: Can't close fd FD_VALUE` to STDERR.


4. elf_header (Advanced)

### Description

This program displays the information contained in the ELF header at the start of an ELF file.

### Usage

elf_header elf_filename


- If the file is not an ELF file or encounters an error, it exits with status code `98` and displays a comprehensive error message to STDERR.
- It uses `lseek` once and `read` a maximum of 2 times at runtime.
- It displays information in the format of `readelf -h (version 2.26.1)`.

---

compiler used : gcc -Wall -pedantic -Werror -Wextra -std=gnu89


