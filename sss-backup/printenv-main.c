#include "shell_functions.h"
#include "shell_strings.h"
/* #include "holberton.h" */
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	char **env1;
	(void) ac;
	(void) av;

	env1 = env;
	_printenv(env1);
	/* while (*env1) */
	/* { */
	/* 	write (STDOUT_FILENO, *env1, _strlen(*env1)); */
	/* 	env1++; */
	/* } */
	exit (EXIT_SUCCESS);
}
