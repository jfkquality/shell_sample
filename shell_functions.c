#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

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

/* read_file function */

/**
 * _printenv - prints the environment
 * @env: environment variable
 *
 * Return: Always 0.
 */
int _printenv(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
/**
 * type_prompt - type ($) prompt
 *
 * Return: nothing
 */
void type_prompt()
{
	write(STDOUT_FILENO, "$ ", 2);
}
/**
 * sigintHandler - prevent Ctrl-C from killing the shell
 * signum - signal number
 *
 * Return: nothing
 */
void sigintHandler(int signum)
{
	signal(signum, SIG_IGN);
	write(STDOUT_FILENO, "\n", 1);
	type_prompt();
	signal(SIGINT, sigintHandler);
}
/**
 * check_input - check input for ctrl-d, exit
 * @read: num of characters in line
 * @line: input line
 *
 * Return:
 */
void check_input(ssize_t read, char *line)
{
	if (read == -1)
	{
		/* free(line); */
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(line, "exit\n") == 0)
	{
		if (line)
			free(line);
		/* write(STDIN_FILENO, "\n", 1); */
		exit(EXIT_SUCCESS);
	}
}
/**
 * make_arr - make the command args array 
 * @read: number of chars in line
 * @line: input line
 *
 * Return: array
 */
char **make_arr(ssize_t read, char *line)
{
	int toklen = 0, i = 0, rows = 0, k = 0;
	char **arr;
	char *token; /* *toktmp = NULL; */

	token = strtok(line, " \n");
	if (!token)
	{
		/* free(line); */
	  return (0);
	}
	arr = malloc(read * sizeof(char*));
	if (arr == NULL)
		{
			if (line)
				free(line);
			exit (EXIT_FAILURE);
		}
	i = 0;
	rows = 0;
	toklen = getlen(token);
	arr[i] = malloc((toklen) * sizeof(char));
	if (arr[i] == NULL)
	{
		free(arr);
		free(line);
		exit (EXIT_FAILURE);
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
			exit (EXIT_FAILURE);
		}
		arr[i] = token;
		rows++;
	}
	arr[i + 1] = NULL;
	rows++;
	return (arr);
}
/**
 * _execute - execute entered command
 * @line: input line
 * @args: list of cmd line args
 * @envp: environment variable
 *
 * Return: nothing
 */
void _execute(char *line, char **args, char **envp)
{
	pid_t child_pid;
	unsigned int k = 0;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		if(line)
			free(line);
		if (args)
		{
			for (k = 0; k <= sizeof(args); k++)
				free(args[k]);
			free(args);
			exit (EXIT_FAILURE);
		}
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("Error:");

			if (line)
				free(line);
			if(args)
			{
				for (k = 0; k < sizeof(args) - 1; k++)
				{
					free(args[k]);
					k++;
				}
				free(args);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		wait(&status);
	}
}

