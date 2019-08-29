
#include "shell_functions.h"
#include "shell_strings.h"

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

/**
 * _strncmp - compare n characters in 2 stings
 * @s1: string pointer parameter
 * @s2: string pointer parament
 * @n: limiter
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
