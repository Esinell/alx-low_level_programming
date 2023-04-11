#include "main.h"

/**
* append_text_to_file - Appends text to the end of a file.
* @filename: A pointer to the name of the file.
* @text_content: A pointer to the string to append to the file.
*
* Return: If the function fails or filename is NULL - -1.
* If the file does not exist or the user lacks write permissions - -1.
* Otherwise - 1.
*/
	int append_text_to_file(const char *filename, char *text_content)
	{
	int file_desc, write_status, text_len = 0;

	if (filename == NULL)
	return (-1);

	if (text_content != NULL)
	{
	for (text_len = 0; text_content[text_len];)
	text_len++;
	}

	file_desc = open(filename, O_WRONLY | O_APPEND);
	write_status = write(file_desc, text_content, text_len);

	if (file_desc == -1 || write_status == -1)
	return (-1);

	close(file_desc);

	return (1);
	}
