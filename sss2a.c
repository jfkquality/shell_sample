#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell_functions.h"

/* extern char **environ; */
extern int errno;

int main(int ac, char **av, char **env)
{
	FILE *fp;
	/* int fd; */
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *toktmp = NULL;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	/* char s[100];  */ /* for chdir e.g. below */
	/* char *cd; */
	int toklen = 0, rows = 0;
	unsigned int k, i;
	char **arr;
	char *token; /* *toktmp = NULL; */
	pid_t child_pid;
	int status;

	(void) argv;
	(void) toktmp;
	(void) ac;
	(void) av;
	(void) env;

	/* fp = STDIN_FILENO; */
	fp = stdin;

	/* while (*environ) */
	/*   { */
	/*     printf("%s\n", *environ); */
	/*     environ++; */
	/*   } */


	/* printing current working directory  */
	/* printf("%s\n", getcwd(s, 100));  */
	/* using the command  */
	/* chdir("..");  */
	/* printing current working directory  */
	/* printf("%s\n", getcwd(s, 100));  */
	/* using the command  */
	/* chdir("..");  */
	/* printing current working directory  */
	/* printf("%s\n", getcwd(s, 100));  */
  

	/* while ((read = getline(&line, &len, fp)) != -1) */
	while (1)
	{
		type_prompt();
		signal(SIGINT, sigintHandler);

		if ((read = getline(&line, &len, fp)) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		else
		{
			if (strcmp(line, "exit\n") == 0)
			{
				free(line);
				/* write(STDIN_FILENO, "\n", 1); */
				exit(EXIT_SUCCESS);
			}

			/* Parse line and make array */
			/* input_args = make_arr(read, line); */

			token = strtok(line, " \n");
			if (!token)
			{
				continue;
			}
			arr = malloc((read) * sizeof(char) + 1);
			if (arr == NULL)
			{
				free(line);
				exit (-1);
			}
			i = 0;
			rows = 0;
			toklen = getlen(token);
			arr[i] = malloc((toklen) * sizeof(char));
			if (arr[i] == NULL)
			{
				free(arr);
				free(line);
				exit (-1);
			}
			arr[i] = token;
			rows++;

			while ((token = strtok(NULL, " \n")))
			{
				i++;
				toklen = getlen(token);
				arr[i] = malloc((toklen) * sizeof(char));
				if (arr[i] == NULL)
				{
					for (k = 0; k < i - 1; k++)
						free(arr[k]);
					free(arr);
					free(line);
					exit (-1);
				}
				arr[i] = token;
				rows++;
			}
			arr[i + 1] = NULL;
			rows++;
		}
			/* Line read and parsed. Execute command */
			/* _execute(line, arr); */
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				free(line);
				for (k = 0; k < sizeof(arr) - 1; k++)
					free(arr[k]);
				free(arr);
				exit (-1);
			}
			if (child_pid == 0)
			{
				if (execve(arr[0], arr, environ) == -1)
				{
					/* i = 0; */
					/* while (arr[i]) */
					/*   free(arr[i]); */
					/* free(arr); */
					perror("Error:");
					exit(-1);
				}
			}
			else
			{
				wait(&status);
			}
	}
	/* write(STDIN_FILENO, "\n", 1); */
	free(line);
	/* free(token); */
	/* for (i = 0; i < rows; i++) */
	/* 	free(arr[i]); */
	/* free(arr); */
	exit(EXIT_SUCCESS);
}
