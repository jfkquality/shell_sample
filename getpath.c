#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell_functions.h"
/**
 * get_env_var - get PATH variable from environ/envp
 * @env: environment (envp)
 * @evar: env variable to get
 *
 * Return: char ptr to env var
 */
char *_get_env_var(char **env, char *evar)
{
	int len;
	int i, j;
	char *p;
	/* char *vars[] = {"PATH=", "_=", "OLDPWD=", "HOME="}; */
	(void) ac;
	(void) av;

	i = 0;
	len = 0;
	while (env[i])
	{
		j = 0;
		p = env[i];
		while (vars[j])
		{
			if (_strncmp(vars[j], p, _strlen(vars[j])) == 0)
			{
				len = _strspn(p, vars[j]);
				printf("len is %d.\n%s.\nFound on line = %d.\n", len, p, i);
			}
			j++;
		}
		i++;
	}
	return (0);
}


	int i = 0;
	char *p;
	char *path = "PATH=";
	char **env1;
	/* char **envstart; */
	/* char **envend; */

	env1 = env;
	/* envstart = env; */
	/* envend = env; */
	while (*env1)
	{
	  p = _strstr(*env, path);
	  printf("PATH=? %s\n", *env1);
	  i++;
	}
	return (p + _strspn(*env, path));
}
