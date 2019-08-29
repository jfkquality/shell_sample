#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	int toklen = 0, i = 0, j = 0, k = 0, rows = 0;
	ssize_t read;
	char **arr;
	pid_t child_pid;
	int status;
	/* char *PATH = "/bin/"; */
	/* char *envp[3]; */

	/* envp[0] = "/bin/ls"; */
	/* envp[1] = "-l"; */
	/* envp[2] = "/usr/"; */
	/* envp[2] = NULL; */

	fp = stdin;
	write(1, "$ ", 2);
	while ((read = getline(&line, &len, fp)) != -1);
	{
		i = 0;
		j = 0;
		rows = 0;
		token = strtok(line, " ,;\'\"");
		if (strcmp(token, "exit\n") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		arr = malloc((len + 1) * sizeof(char) + 1);
		if (arr == NULL)
			return (-1);

		toklen = getlen(token);
		i = 0;
		arr[i] = malloc((toklen + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free(arr);
			return (-1);
		}
		/* arr[i] = token; */
		for (j = 0; j < toklen; j++, token++)
			arr[i][j] = *token;
		arr[i][j] = '\0';
		rows++;
		/* write(1, token, getlen(token)); */

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
			/* arr[i] = token; */
			for (j = 0; j < toklen; j++, token++)
				arr[i][j] = *token;
			arr[i][j] = '\0';
			rows++;
		}
		arr[i + 1] = NULL;
		rows++;
		/* for (i = 0; i < rows; i++) */
		/*   printf("%d. %s", rows, arr[i]); */

		/* char *argv[] = {"/bin/ls", "-l", "/usr/", NULL}; */

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
                        return (1);
		}
		if (child_pid == 0)
		{
		    printf("I'm executing\n");
		  if (execve(arr[0], arr, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
		  printf("I'm waiting\n");
                        wait(&status);
		}

		write(1, "$ ", 2);
	}
	write(1, "\n", 1);
	/* free(line); */
	free(token);
	for (i = 0; i < rows; i++)
		free(arr[i]);
	free(arr);
	exit(EXIT_SUCCESS);
}
