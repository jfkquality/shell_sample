#include "shell_functions.h"
/* #include "holberton.h" */
#include <stdio.h>

int main(int ac, char **av, char **env)
{
  (void) ac;
  (void) av;

  parsepath(env);

  return (0);
}
