#include "shell_functions.h"
/* #include "holberton.h" */
#include <stdio.h>

int main(int ac, char **av, char **env)
{
  /* int len; */
  /* int i = 0; */
  /* char *p; */
  /* char *vars[] = {"PATH=", "_=", "OLDPWD=", "HOME="}; */
  (void) ac;
  (void) av;
  (void) env;

  parsepath();

  /* if (ac != 2) */
  /* { */
  /* 	write (STDOUT_FILENO, "Usage ", 6); */
  /* 	write (STDOUT_FILENO, av[0], _strlen(av[0])); */
  /* 	write (STDOUT_FILENO, " <var-name>\n", 12); */
  /* 	return (-1); */
  /* } */

  /* while (vars[i]) */
  /* { */
  /* 	p = _getenv(env, av[1]); */
  /* 	printf("%s\n", p); */
  /* 	i++; */
  /* } */
  /* i = 0; */
  /* len = 0; */
  /* while (env[i]) */
  /* { */
  /*   j = 0; */
  /*   p = env[i]; */
  /*   while (vars[j]) */
  /*   { */
  /*     if (_strncmp(vars[j], p, _strlen(vars[j])) == 0) */
  /*     { */
	/* len = _strspn(p, vars[j]); */
  /* 	printf("%s\n", p); */
  /*     } */
  /*     j++; */
  /*   } */
  /*   i++; */
  /* } */
  return (0);
}
