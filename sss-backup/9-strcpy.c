#include "holberton.h"
#include <stdio.h>

/**
 * _strcpy - Copy a src string to a dest string
 * @dest: string pointer parameter
 * @src: string pointer parament
 * Return: dest.
 */


	char *_strcpy(char *dest, char *src)
{

	char *src2 = src;
	char *dest2 = dest;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (; *src2 != '\0'; src2++, dest2++)
	{
		*dest2 = *src2;
	}
	*dest2 = *src2;

	return (dest);
}
