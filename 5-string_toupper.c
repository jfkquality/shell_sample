#include "holberton.h"
#include <stdio.h>

/**
 * string_toupper - convert lower to uppercase
 * @str: passed array as pointer
 * Return: string
 */
char *string_toupper(char *str)
{
	char *s1 = str;

	while (*s1 != '\0')
	{
		if (*s1 >= 'a' && *s1 <= 'z')
			*s1 = *s1 - 32;
		s1++;
	}
	return (str);
}
