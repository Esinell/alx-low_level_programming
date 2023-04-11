#include "main.h"

/**
* clear_bit - sets the value of a given bit to 0
* @num_ptr: pointer to the number to modify
* @bit_index: index of the bit to clear
*
* Return: 1 for success, -1 for failure
*/
int clear_bit(unsigned long int *num_ptr, unsigned int bit_index)
{
	/*
	 * If the bit_index is greater than 63 (the maximum index), return -1 */
	if (bit_index > 63)
	return (-1);

	/* Set the bit at bit_index to 0 using a bitwise..
	 * AND operator and return 1 for success */
	*num_ptr = (~(1UL << bit_index) & *num_ptr);
	return (1);
}

