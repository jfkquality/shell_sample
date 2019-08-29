#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell_functions.h"
/**
 * getenv - get PATH variable from environ/envp
 * @env: environment (envp)
 * @evar: env variable to get
 *
 * Return: char ptr to env var
 */
char *_getenv(char **env, char *evar)
{
	int i = 0;

	while (env[i])
	{
		if (_strncmp(evar, env[i], _strlen(evar)) == 0)
		{
			return (env[i]);
		}
		i++;
	}
	return (0);
}
