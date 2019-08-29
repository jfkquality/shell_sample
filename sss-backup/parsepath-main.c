#include "shell_functions.h"
#include "shell_strings.h"

int main(int ac, char **av, char **env)
{
  (void) ac;
  (void) av;

  parsepath(env);

  return (0);
}
