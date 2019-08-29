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
        unsigned int i = 0;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        char *toktmp = NULL;
        char **input_args;
        char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
        /* char s[100];  */ /* for chdir e.g. below */
        /* char *cd; */
        (void) argv;
        (void) toktmp;
        (void) ac;
        (void) av;

	/* fp = STDIN_FILENO; */
	fp = stdin;

	/* while ((read = getline(&line, &len, fp)) != -1) */
	while (1)
	{
		type_prompt();
		signal(SIGINT, sigintHandler);
		read = getline(&line, &len, fp);
		check_input(read, line);
                input_args = make_arr(read, line);
		if (!input_args)
		{
		  /* free(line); */
		  continue;
		}
                _execute(line, input_args, env);
	}
	/* write(STDIN_FILENO, "\n", 1); */
	/* if (line) */
		free(line);
	/* if (input_args) */
	/* { */
		for (i = 0; i < sizeof(input_args); i++)
			free(input_args[i]);
		free(input_args);
		exit(EXIT_SUCCESS);
	/* } */
}
