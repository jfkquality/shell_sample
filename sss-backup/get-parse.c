#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	char *token;
	size_t len = 0;
	size_t wcount = 0;
	ssize_t read;
	char **arr;

	/* len = malloc(sizeof(1024)); */

	fp = stdin;
	write(1, "$ ", 2);
	while ((read = getline(&line, &len, fp)) != -1)
	{
	  /* printf("Retrieved line of length %lu :\n", read); */
	  /* printf("%s", line); */
	  token = strtok(line, " -,");
	  if (strcmp(token, "exit\n") == 0)
	  {
	    free(line);
	    exit(EXIT_SUCCESS);
	  }
	  write(1, token, strlen(token));
	  while ((token = strtok(NULL, " -,")))
	  {
	    write(1, "\n", 1);
	    write(1, token, strlen(token));
	  }
	  write(1, "$ ", 2);
	}
	write(1, "\n", 1);
	free(line);
	/* free(token); */
	exit(EXIT_SUCCESS);
}
