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
	char *line = NULL;
	char *line1 = NULL;
	char *token;
	char *token2;
	size_t len = 0;
	/* int toklen = 0; */
	int toklens = 0;
	int wcount = 0;
	int i = 0;
	int k = 0;
	/* int j = 0; */
	ssize_t read;
	char **arr;

	/* len = malloc(sizeof(1024)); */

	fp = stdin;
	write(1, "$ ", 2);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line1 = line;
		token = strtok(line, " -,");
		if (strcmp(token, "exit\n") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		wcount = 1;
		toklens = getlen(token);
		/* write(1, token, strlen(token)); */
		while ((token = strtok(NULL, " -,")))
		{
			wcount++;
			toklens += getlen(token);
			/* write(1, "\n", 1); */
			/* write(1, token, strlen(token)); */
		}

		printf("wcount = %d\n", wcount);

		arr = malloc((toklens + wcount) * sizeof(char) + 1);
		if (arr == NULL)
			return (-1);

		token2 = strtok(line1, " -,");
		i = 0;

		/* for (i = 0; i < wcount; i++) */
		while (i < wcount)
		{
			arr[i] = malloc(getlen(token2) * sizeof(char) + 1);
			if (arr[i] == NULL)
			{
				for (k = 0; k < i; k++)
					free(arr[k]);
				free(arr);
				return (-1);
			}
			arr[i] = token2;
			token2 = strtok(NULL, " -,");
			i++;
		}
		printf("i = %d\n", i);
		i = 0;
		/* for (i = 0; i < wcount; i++) */
		while (arr[i])
		{
 			write(1, arr[i], getlen(arr[i]));
			write(1, "\n", 1);
			i++;
		}
		write(1, "$ ", 2);
	}
	write(1, "\n", 1);
	free(line);
	/* free(token); */
	exit(EXIT_SUCCESS);
}
