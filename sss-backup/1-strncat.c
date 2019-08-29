#include "holberton.h"
#include <stdio.h>

/**
 * _strncat - Concatenate a src string to a dest string
 * @src: string pointer parameter
 * @dest: string pointer parameter
 * @n: int characters to concatenate
 * Return: dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *dest2 = dest;
	char *src2 = src;
	int i = 0;

	for (; *dest2 != '\0'; dest2++)
		;

	for (i = 0; i < n && *src2 != '\0'; i++, src2++, dest2++)
		*dest2 = *src2;
	*dest2 += '\0';

	return (dest);
}
