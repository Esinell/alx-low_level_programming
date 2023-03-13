#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenate two strings
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 *
 * Return: pointer to concatenated string, NULL if fail
 */
char *str_concat(char *s1, char *s2)
{
	char *conct;
	int i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	i = j = 0;
	while (s1[i] != '\0')
		i++;

	while (s2[j] != '\0')
		j++;

	conct = malloc(sizeof(char) * (i + j + 1));

	if (conct == NULL)
		return (NULL);

	i = j = 0;
	while (s1[i] != '\0')
	{
		conct[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0')
	{
		conct[i] = s2[j];
		i++, j++;
	}

	conct[i] = '\0';

	return (conct);
}

