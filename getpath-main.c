#include "shell_functions.h"
#include "holberton.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
  int len;
  int i, j;
  char *p;
  char *vars[] = {"PATH=", "_=", "OLDPWD=", "HOME="};
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
