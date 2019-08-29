#include "holberton.h"
#include <stdio.h>

/**
 * _strcat - Concatenate a src string to a dest string
 * @dest: string pointer parameter
 * @src: string pointer parament
 * Return: dest.
 */
char *_strcat(char *dest, char *src)
{
	char *dest2 = dest;
	char *src2 = src;

	for (; *dest2 != '\0'; dest2++)
		;

	for (; *src2 != '\0'; src2++, dest2++)
		*dest2 = *src2;
	*dest2 = *src2;

	return (dest);
}
