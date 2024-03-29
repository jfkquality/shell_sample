#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
  char *str, *token;
  ssize_t check;
  size_t size = sizeof(1024);
  str = malloc(size);
  while((check = getline(&str, &size, stdin) != -1))
    {
      token = strtok(str, " ");
      if (strcmp(token, "exit \n") == 0)
	{
	  free(str);
	  exit(EXIT_SUCCESS);
	}
      write(1, token, strlen(token));
      while((token = strtok(NULL, " -")))
	{
	  write(1, "\n", 1);
	  write(1, token, strlen(token));
	}
    }
  return (0);
}
