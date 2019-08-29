#include "shell_functions.h"
#include "shell_strings.h"

/**
 * parsepath - parse PATH variable retrieved from getenv()
 * @env: environment (envp)
 * @evar: env variable to get
 *
 * Return: char ptr to env var
 */
char **parsepath(char**env)
{
	int i = 0, j = 0;
	int paths = 0;
	int colons = 0;
	int pathlen;
	char *prefix = "PATH=";
	char *path = NULL;
	char *pathonly = NULL;
	char *nextpath = NULL;
	char *nextcolon = NULL;
	char *lastpath = NULL;
	char **patharr;

	path = _getenv(env, prefix);

	pathonly = path + _strlen(prefix);
	printf("%s\n", pathonly);
	nextpath = pathonly;
	nextcolon = pathonly;
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
	printf("NUMBER OF PATHS %d\n", paths);

	patharr = malloc(paths * sizeof(char *));
	nextcolon = _strchr(pathonly, ':'); /* + 1; */
	i = 0;
	while (nextcolon != NULL)
	{
		pathlen = nextcolon - nextpath;
		patharr[i] = malloc((pathlen + 1) * sizeof(char));
		lastpath = malloc((pathlen + 1) * sizeof(char));
		/* printf("%d ", colons); */
		j = 0;
		while (nextpath < nextcolon)
		{
			patharr[i][j] = *nextpath;
			nextpath++;
			j++;
		}
		patharr[i][j] = '\0';
		printf("patharr[%d] = %s\n", i, patharr[i]);
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
			printf("%d %s\n", colons, lastpath);
		}
	}
	return (0);
}
