#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
 * main - getline/read and strtok/parse a line into array
 *
 * return: int
 */
int
main(void)
{
	FILE *fp;
	char *line = NULL, *token;
	size_t len = 0;
	int toklen = 0, i = 0, k = 0, rows = 0;
	ssize_t read;
	char **arr;

	fp = stdin;
	write(1, "$ ", 2);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		i = 0;
		rows = 0;
		token = strtok(line, " ,;\'\"");
		if (strcmp(token, "exit\n") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		arr = malloc((read) * sizeof(char) + 1);
		if (arr == NULL)
			return (-1);

		toklen = getlen(token);
		arr[i] = malloc((toklen + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free(arr);
			return (-1);
		}
		arr[i] = token;
		rows++;

		while ((token = strtok(NULL, " ,;\'\"")))
		{
			i++;
			toklen = getlen(token);
			arr[i] = malloc((toklen + 1) * sizeof(char));
			if (arr[i] == NULL)
			{
				for (k = 0; k < i - 1; k++)
					free(arr[k]);
				free(arr);
				return (-1);
			}
			arr[i] = token;
			rows++;
		}
		for(i = 0; i < rows; i++)
		{
			write(1, arr[i], getlen(arr[i]));
			write(1, "\n", 1);
		}
		write(1, "$ ", 2);
	}
	write(1, "\n", 1);
	free(line);
	/* free(token); */
	/* for (i = 0; i < rows; i++) */
	/* 	free(arr[i]); */
	/* free(arr); */
	exit(EXIT_SUCCESS);
}
