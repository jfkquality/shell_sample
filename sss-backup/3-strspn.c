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
