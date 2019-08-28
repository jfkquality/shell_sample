#include "shell_functions.h"
#include "shell_strings.h"
/* #include "holberton.h" */
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	char *p;
	char *av1;
	(void) ac;
	(void) av;

	av1 = _strdup(av[1]);

	if (ac != 2)
	{
		write (STDOUT_FILENO, "Usage ", 6);
		write (STDOUT_FILENO, av[0], _strlen(av[0]));
		write (STDOUT_FILENO, " <var-name>\n", 12);
		return (-1);
	}

	p = _getenv(env, av1);
	printf("%s\n", p);
	return (0);
}
