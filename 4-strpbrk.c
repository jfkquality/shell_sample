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
