#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"


/**
 * getlen - get length of string.
 * @s: string pointer
 * Return: length
 */
int getlen(char *s)
{
	int l = 0;
	char *s11 = s;

	for (; *s11; s11++, l++)
		;
	return (l);
}

/**
 * _strchr - finc char in a string
 * @s: pointer to string to search
 * @c: character to find
 *
 * Return: pointer to found char or NULL.
 */
/* char *_strchr(char *s, char c) */
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
 * make_arr - make array of words
 * @wcount: word count
 * @l: len of input str stripped of extra spaces
 * @wd: input string stripped of extra spaces
 *
 * Return: pointer to array
 */
char **make_arr(int wcnt, int l, char *wd)
{
	int i = 0, j = 0, k = 0, wlen = 0;
	char **wordarr = NULL;
	char *wd1;

	wd1 = wd;

	wordarr = malloc((l + wcnt) * sizeof(char) + 1);
	if (wordarr == NULL)
		return (NULL);
	for (i = 0; i < wcnt; i++, wd++, wd1++)
	{
		wlen = 0;
		for (; *wd != ' '; wlen++, wd++) /* count wlen w one ptr */
			;
		/* printf("wlen = %d\n", wlen); */
		wordarr[i] = malloc((wlen) * sizeof(char) + 1);
		if (wordarr[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(wordarr[k]);
			free(wordarr);
			return (NULL);
		}
		j = 0;
		/* for (j = 0; j < wlen; j++, wd1++) */
		for (; *wd1 != ' '; j++, wd1++) /* copy the word w 2nd ptr */
			wordarr[i][j] = *wd1;
		wordarr[i][j] = '\0';
		/* printf("word added to arr[%d] %s\n", i, wordarr[i]); */
	}
	return (wordarr);
}
/**
 * strtow - parse a string into array of words
 * @str: the string to parse
 *
 * Return: pointer to array
 */
/* get the length of the string. */
/* allocate space for a 2D array from len of string */
/* allocate rows based on the length of the words */
/* count the number of words in the string => array rows */
/* keep track of the start of a word. */
/* end of a word is when a space is found */
/* start of next word is when the space(s) end */

/* char *argstostr(int ac, char **av) */
char **strtow(char *str)
{
	int len = 0, wcount = 0, spaces = 0;
	char *p, *p1, *str1, *wstart, *wend = NULL, *word = NULL;
	char **words = NULL;

	if (str == NULL)  /* (str == "" || str == NULL) */
		return (NULL);
	p = malloc(getlen(str) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	str1 = str;
	wstart = str;
	wend = str;
	p1 = p;
	while (*str1)
	{
	  /* printf("str1 %s wstart %s\n", str1, wstart); */
		spaces = 0;
		for (; *str1 == ' ' && *str1; str1++, spaces++) /* skip spaces to find word */
			;
		/* printf("spaces %d\n", spaces); */
		wstart = str1;
		for (; *str1 != ' ' && *str1; str1++, len++) /* get word */
			;
		/* printf("len %d\n", len); */
		wend = str1 - 1;
		for (; wstart <= wend; p1++, wstart++)
			*p1 = *wstart; /* use words not p */
		*p1 = ' ';
		p1++;
		/* len++; */
		*p1 = '\0';
		wcount++;
		/* wstart = str1; */
		/* printf("str1 %s wstart %s wcount %d\n", str1, wstart, wcount); */
	}
	word = p;
	/* printf("word = %s len = %d wcount = %d\n", word, len, wcount); */
	/* words = malloc((len + wcount) * sizeof(char) + 1); */
	words = make_arr(wcount, len, word);
	/* printf("word = %s words = %s\n", word, words[0]); */
	return (words);
}
