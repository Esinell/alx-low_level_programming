#include "main.h"

/**
 * set_bit - Sets a bit at a specific index to 1 in a given number.
 * @num_ptr: Pointer to the number to modify.
 * @bit_index: Index of the bit to set to 1.
 *
 * Return: 1 if successful, -1 if failed.
 */

int set_bit(unsigned long int *num_ptr, unsigned int bit_index)
{

/* Check if the bit_index is within the valid range */
if (bit_index > 63)
	return (-1);

/* Set the bit at bit_index to 1 */
*num_ptr = ((1UL << bit_index) | *num_ptr);

	return (1);
}

