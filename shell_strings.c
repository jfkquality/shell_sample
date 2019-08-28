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
#include "holberton.h"

/**
 * _strchr - finc char in a string
 * @s: pointer to string to search
 * @c: character to find
 *
 * Return: pointer to found char or NULL.
 */
char *_strchr(char *s, char c)
{
	char *s1 = s;
	char c1 = c;

	while (*s1)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	if (*s1 == c1)
		return (s1);
	return ('\0');
}
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
	unsigned int i;

	for (i = 0; i < n && *src1 != '\0' && *src2 != '\0'; i++, src1++, src2++)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
	}
	return (0);
}
#include "holberton.h"

/**
 * _strspn - find sub string in a string
 * @s: pointer to string to search
 * @accept: chars to compare tod
 *
 * Return: number of bytes found.
 */
unsigned int _strspn(char *s, char *accept)
{
	char *s1 = s;
	char *acc1 = accept;
	int this_c = 0;
	int total_c = 0;

/* Find if the firsth word in s1 has all the chars of acc1 and return len */

	while (*s1)
	{
		acc1 = accept;
		this_c = 0;
		while (*acc1)
		{
			if (*s1 == *acc1)
			{
				this_c++;
				total_c++;
				break;
			}
			acc1++;
		}
		if (this_c == 0)
			return (total_c);
		s1++;
	}
	return (total_c);
}
#include "holberton.h"

/**
 * _strpbrk - finc sub string in a string
 * @s: pointer to string to search
 * @accept: chars to compare tod
 *
 * Return: pointer to found char or NULL.
 */
char *_strpbrk(char *s, char *accept)
{
	char *s1 = s;
	char *acc1 = accept;


/* Find if the firsth word in s1 has all the chars of acc1 and return len */

	while (*s1)
	{
		acc1 = accept;
		while (*acc1)
		{
			if (*s1 == *acc1)
			{
				return (s1);
			}
			acc1++;
		}
		s1++;
	}
	return (0);
}
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
#include "holberton.h"
#include <stdio.h>

/**
 * _strstr - find sub string in a string
 * @haystack: pointer to string to search
 * @needle: chars to find
 *
 * Return: pointer to found char or NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	char *hay1 = haystack;
	char *hay2 = haystack;
	char *need1 = needle;
	char *need2 = needle;
	int size_h = 0;
	int size_n = 0;

	/* Find len of both strings */
	for (; *hay1; hay1++, size_h++)
		;
	for (; *need1; need1++, size_n++)
		;

	/* If you reach the end of the search string, you’ve found it! ‘ */
	/* Otw, look again until the end of the original string */
	/* or too close to the end for the search string to fit. */

	/* If not found or at end or almost end of str*/
	while (hay2 < hay1 - size_n + 1)
	{
		need2 = needle;

		while (*need2)
		{
			if (*hay2 != *need2)
				break;
			hay2++;
			need2++;
		}
		if (!*need2)
			return (hay2 - size_n);
		hay2++;
	}
	return (0);
}
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
