#include "shell_functions.h"
#include "shell_strings.h"

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

/**
 * _strncat - Concatenate a src string to a dest string
 * @src: string pointer parameter
 * @dest: string pointer parameter
 * @n: int characters to concatenate
 * Return: dest.
 */
char *_strncat(char *dest, char *src, size_t n)
{
	char *dest2 = dest;
	char *src2 = src;
	unsigned int i = 0;

	for (; *dest2 != '\0'; dest2++)
		;

	for (i = 0; i < n && *src2 != '\0'; i++, src2++, dest2++)
		*dest2 = *src2;
	*dest2 += '\0';

	return (dest);
}

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
