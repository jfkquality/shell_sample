#include "shell_functions.h"
#include "shell_strings.h"

/**
 * _env - print environment
 * @env: envp
 *
 * Return: nothing
 */
void _env(char **env)
{
	char **env1;

	env1 = env;

	while (*env1)
	{
		write(STDOUT_FILENO, *env1, _strlen(*env1));
		write(STDOUT_FILENO, "\n", 1);
		env1++;
	}
	exit(EXIT_SUCCESS);
}

/**
 * _getenv - get requested variable from environ/envp
 * @env: environment (envp)
 * @evar: env variable to get
 *
 * Return: char ptr to env var
 */
char *_getenv(char **env, char *evar)
{
	int i = 0;

	if (!_strchr(evar, '='))
		_strcat(evar, "=");

	while (env[i])
	{
		if (_strncmp(evar, env[i], _strlen(evar)) == 0)
			return (env[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}

/**
 * _printenv - prints the environment
 * @env: environment variable
 *
 * Return: Always 0.
 */
void _printenv(char **env)
{
	/* unsigned int i = 0; */

	/* while (env[i]) */
	/* { */
	/*	printf("%s\n", env[i]); */
	/*	i++; */
	/* } */
	/* return (0); */
	_env(env);
	exit(EXIT_SUCCESS);
}

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
 * type_prompt - type ($) prompt
 *
 * Return: nothing
 */
void type_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}


