#include "shell_functions.h"
#include "shell_strings.h"

/**
 * sigintHandler - prevent Ctrl-C from killing the shell
 * @signum: signal number
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

/* char *_getline(char **lineptr, ssize_t *n, int stream) */

/**
 * _getline - read line from stdin
 * @buff: string buffer
 *
 * Return: count of characters read.
 */
ssize_t _getline(char *buff)
{
	int fd = STDIN_FILENO;
	int count = 1024;
	ssize_t readcnt;

	buff = malloc(count * sizeof(size_t));
	readcnt = read(fd, buff, count);
	buff[count] = '\0';

	printf("readcnt %lu\n", readcnt);
	return (readcnt);
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
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(line, "exit\n") == 0)
	{
		free(line);
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
	char **arr, *token;

	token = strtok(line, " \n");
	if (!token)
		return (0);
	arr = malloc(read/2 * sizeof(char *));
	if (arr == NULL)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	toklen = getlen(token);
	arr[i] = malloc((toklen) * sizeof(char));
	if (arr[i] == NULL)
	{
		free(arr);
		free(line);
		exit(EXIT_FAILURE);
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
			exit(EXIT_FAILURE);
		}
		arr[i] = token;
		rows++;
	} arr[i + 1] = NULL;
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
		free(line);
		for (k = 0; k <= sizeof(args); k++)
			free(args[k]);
		free(args);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("Error:");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
