#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a given text file and...
 * writes its contents to the standard output.
 * @filename: The name of the text file to read.
 * @letters: The number of bytes to read from the text file.
 * Return: The actual number of bytes read and printed to the standard output.
 * Returns 0 if the function fails or if the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

