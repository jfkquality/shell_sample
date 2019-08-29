#include "holberton.h"
#include <stdio.h>

/**
 *  _strlen - recursion. get len of str
 * @s: string pointer parameter
 *
 * Return: length int
 */
int _strlen(char *s)
{
	char *s1 = s;

	if (*s1 != '\0')
	{
		return (1 + _strlen(s1 + 1));
	}
	return (0);
}
