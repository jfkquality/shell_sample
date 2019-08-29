#include "shell_strings.h"
#include "shell_functions.h"

/**
 * main - primary function to run shell from
 * @ac: arguement count
 * @av: arguement vector
 * @env: environment
 *
 * Return: nothing
 */

int main(int ac, char **av, char **env)
{
	FILE *fp;
	unsigned int i = 0;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *toktmp = NULL;
	char **input_args;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	(void) argv;
	(void) toktmp;
	(void) ac;
	(void) av;

	/* fp = STDIN_FILENO; */
	fp = stdin;

	while (1)
	{
		type_prompt();
		signal(SIGINT, sigintHandler);
		read = getline(&line, &len, fp);
		check_input(read, line);
		input_args = make_arr(read, line);
		if (!input_args)
		{
			continue;
		}
		_execute(line, input_args, env);
	}
	free(line);
	for (i = 0; i < sizeof(input_args); i++)
		free(input_args[i]);
	free(input_args);
	exit(EXIT_SUCCESS);
}
