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
	_env(env1);
	exit (EXIT_SUCCESS);
}
