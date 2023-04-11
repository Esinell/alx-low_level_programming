#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *filename);
void close_file_descriptor(int fd);

/**
* allocate_buffer - Allocates 1024 bytes for a buffer to store file contents.
* @filename: The name of the file whose contents will be stored in the buffer.
*
* Return: A pointer to the newly-allocated buffer.
*/
char *allocate_buffer(char *filename)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
exit(99);
}

return (buffer);
}

/**
* close_file_descriptor - Closes a file descriptor.
* @fd: The file descriptor to be closed.
*/
void close_file_descriptor(int fd)
{
int close_result;

close_result = close(fd);

if (close_result == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
exit(100);
}
}

/**
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: Exits with code 97 if the argument count is incorrect.
* Exits with code 98 if file_from does not exist or cannot be read.
* Exits with code 99 if file_to cannot be created or written to.
* Exits with code 100 if file_to or file_from cannot be closed.
*/
int main(int argc, char *argv[])
{
int from_fd, to_fd, read_result, write_result;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = allocate_buffer(argv[2]);
from_fd = open(argv[1], O_RDONLY);
read_result = read(from_fd, buffer, 1024);
to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (from_fd == -1 || read_result == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

write_result = write(to_fd, buffer, read_result);
if (to_fd == -1 || write_result == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

read_result = read(from_fd, buffer, 1024);
to_fd = open(argv[2], O_WRONLY | O_APPEND);

} while (read_result > 0);

free(buffer);
close_file_descriptor(from_fd);
close_file_descriptor(to_fd);

return (0);
}

