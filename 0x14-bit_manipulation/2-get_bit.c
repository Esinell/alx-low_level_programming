#include "main.h"

/**
* get_bit - returns the value of a bit at a given index in a decimal number
* @num: decimal number to search
* @index: index of the bit to retrieve
*
* Return: the value of the bit at the given index,..
* or -1 if the index is invalid
*/
int get_bit(unsigned long int num, unsigned int index)
{
int bit_value;

if (index > 63)
return (-1);

/*
* Shift the bit at the given index to the least significant position,
* then retrieve it using a bitwise AND operation with 1.
*/
bit_value = (num >> index) & 1;

return (bit_value);
}

