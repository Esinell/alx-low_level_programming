#include "main.h"

/**
 * get_endianness - Determines the endianness of the machine by checking the..
 * value of the least significant byte of an integer.
 *
 * Return: 0 if the machine is big endian, 1 if it is little endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *byte_pointer = (char *)&num;

	if (*byte_pointer == 1)
	{
		/* Little endian */
		return (1);
	}
	else
	{
		/* Big endian */
		return (0);
	}
}

