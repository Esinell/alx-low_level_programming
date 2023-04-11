#include "main.h"

/**
 * convertBinaryToDecimal - converts a binary number to decimal
 * @binaryString: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int convertBinaryToDecimal(const char *binaryString)
{
	int i;
	unsigned int decimalValue = 0;

	if (!binaryString)
		return (0);

	for (i = 0; binaryString[i]; i++)
	{
	if (binaryString[i] < '0' || binaryString[i] > '1')
		return (0);
		decimalValue = 2 * decimalValue + (binaryString[i] - '0');
	}

	return (decimalValue);
}

