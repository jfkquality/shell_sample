#include "shell_functions.h"
#include "shell_strings.h"

/**
 * parsepath - parse PATH variable retrieved from getenv()
 * @env: environment (envp)
 *
 * Return: char ptr to env var
 */
char **parsepath(char **env)
{
	int i = 0, j = 0, paths = 0, colons = 0, pathlen;
	char *prefix = "PATH=", *path = NULL, *pathonly = NULL;
	char *nextpath = NULL, *nextcolon = NULL, *lastpath = NULL, **patharr;

	path = _getenv(env, prefix);
	pathonly = path + _strlen(prefix);
	nextpath = pathonly;
	nextcolon = _strchr(pathonly, ':') + 1;
	while (nextcolon != (void *)1)
	{
		lastpath = nextcolon;
		paths++;
		nextcolon = _strchr(nextcolon, ':') + 1;
		if (nextcolon == (void *)1)
		{
			paths++;
			break;
		}
	}
	patharr = malloc(paths * sizeof(char *));
	nextcolon = _strchr(pathonly, ':'); /* + 1; */
	i = 0;
	while (nextcolon != NULL)
	{
		pathlen = nextcolon - nextpath;
		patharr[i] = malloc((pathlen + 1) * sizeof(char));
		j = 0;
		while (nextpath < nextcolon)
		{
			patharr[i][j] = *nextpath;
			nextpath++;
			j++;
		}
		patharr[i][j] = '\0';
		nextpath++;
		colons++;
		i++;
		lastpath = nextcolon + 1;
		nextcolon = _strchr(nextpath, ':'); /* + 1; */
		if (!nextcolon)
		{
			pathlen = _strlen(lastpath);
			patharr[i] = malloc((pathlen + 1) * sizeof(char));
			patharr[i] = lastpath;
			patharr[i + 1] = NULL;
		}
	}
	return (patharr);
}
