#include "main.h"

/**
* create_file - Creates a new file with the given name..
* and writes the given content to it.
* @filename: A pointer to the name of the file to create.
* @text_content: A pointer to a string containing..
* the content to write to the file.
*
* Return: If the function fails, returns -1. Otherwise, returns 1.
*/

int create_file(const char *filename, char *text_content)
{
int file_descriptor, bytes_written, content_length = 0;

	if (filename == NULL)
	return (-1);

	if (text_content != NULL)
{
	for (content_length = 0; text_content[content_length];)
	content_length++;
}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	bytes_written = write(file_descriptor, text_content, content_length);

	if (file_descriptor == -1 || bytes_written == -1)
	return (-1);

	close(file_descriptor);

	return (1);
}

