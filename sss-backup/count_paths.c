



/**
 * countpaths - count # of paths in PATH
 * @env: environment (envp)
 *
 * Return: char ptr to env var
 */
size_t parsepath(char **env)
{
  /* UNFINISHED */
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
}
