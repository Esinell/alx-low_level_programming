#include "main.h"
#include <stdlib.h>

/**
* argstostr - Concatenates all arguments passed as strings
* @ac: Number of arguments passed
* @av: Array of pointers to the arguments
*
* Return: Pointer to concatenated string
*/
char *argstostr(int ac, char **av)
{
int i, j, k = 0, len = 0;
char *str;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
len++;
}

str = malloc(sizeof(char) * (len + ac + 1));
if (str == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
{
str[k++] = av[i][j];
}
str[k++] = '\n';
}
str[k] = '\0';

return (str);
}

