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
