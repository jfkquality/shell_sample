#include "holberton.h"
#include <stdio.h>

/**
 * _strcmp - compare 2 stings
 * @s1: string pointer parameter
 * @s2: string pointer parament
 * Return: The diff between the letters.
 */
int _strcmp(char *s1, char *s2)
{
	char *src1 = s1;
	char *src2 = s2;

	for (; *src1 != '\0' && *src2 != '\0'; src1++, src2++)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
	}
	return (0);
}
