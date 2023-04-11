#include "main.h"

/**
* print_binary - Prints the binary representation..
* of a given unsigned long int.
* @num: The number to convert and print in binary.
*/
void print_binary(unsigned long int num)
{
int i, count = 0;
unsigned long int current_bit;

/* Iterate over all 64 bits in the unsigned long int */
for (i = 63; i >= 0; i--)
{
current_bit = num >> i; /* Shift the number to the current bit position */

/* If the current bit is 1, print it and update the count */
if (current_bit & 1)
{
_putchar('1');
count++;
}
/* If the current bit is 0 and some bits have already been printed, print it */
else if (count)
_putchar('0');
}

/* If no bits were printed, the number is zero */
if (!count)
_putchar('0');
}

