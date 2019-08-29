#include "shell_functions.h"
#include "shell_strings.h"

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

	/* If you reach the end of the search string, youve found it!  */
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

	return (dest);
}

/**
 * _strncpy - Copy a src string to a dest string
 * @dest: string pointer parameter
 * @src: string pointer parament
 * @n: int chars to copy
 * Return: dest.
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	char *dest2 = dest;
	char *src2 = src;
	unsigned int i = 0;

	for (i = 0; i < n && *src2 != '\0'; i++, src2++, dest2++)
		*dest2 = *src2;
	/* *dest2 += '\0'; */
	for ( ; i < n; i++, dest2++)
		*dest2 = '\0';
	return (dest);
}
