#include "holberton.h"
#include <stdio.h>

/**
 * _strncpy - Copy a src string to a dest string
 * @dest: string pointer parameter
 * @src: string pointer parament
 * @n: int chars to copy
 * Return: dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *dest2 = dest;
	char *src2 = src;
	int i = 0;

	for (i = 0; i < n && *src2 != '\0'; i++, src2++, dest2++)
		*dest2 = *src2;
	/* *dest2 += '\0'; */
	for ( ; i < n; i++, dest2++)
		*dest2 = '\0';
	return (dest);
}
