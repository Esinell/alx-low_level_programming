#include <stdlib.h>
#include "main.h"

/**
* _memset - fills memory with a constant byte
* @s: pointer to memory area to be filled
* @b: value to set
* @n: number of bytes to fill
*
* Return: a pointer to the memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
*(s + i) = b;
return (s);
}

/**
* _calloc - allocates memory for an array
* @nmemb: number of elements
* @size: size of each element
*
* Return: a pointer to the allocated memory, or NULL if failure
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;

if (nmemb == 0 || size == 0)
return (NULL);

ptr = malloc(nmemb * size);
if (ptr == NULL)
return (NULL);

