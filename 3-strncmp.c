#include "holberton.h"
#include <stdio.h>

/**
 * _strncmp - compare n characters in 2 stings
 * @s1: string pointer parameter
 * @s2: string pointer parament
 * Return: -1 (<), 0 (=) or 1 (>).
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	char *src1 = s1;
	char *src2 = s2;
	int i;

	for (i = 0; i < n && *src1 != '\0' && *src2 != '\0'; i++, src1++, src2++)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
	}
	return (0);
}
