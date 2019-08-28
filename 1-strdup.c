#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer which is a duplicate of the string str.
 * @str: string
 * Return: pointer to array
 */
char *_strdup(char *str)
{

	int l = 0;
	int i = 0;
	char *str1 = str;
	/* int l = strlen(str1); */
	char *p;

	if (!str1)
		return (NULL);

	for (; *str1; l++, str1++)
		;
	l++;
	p = malloc((l) * sizeof(char));

	if (p == NULL)
		return (NULL);

	for (i = 0; i < l; i++)
	  /* printf ("i, l, str[i] = %d, %d, %d\n", i, l, str[i]); */
		p[i] = str[i];

	return (p);

}
