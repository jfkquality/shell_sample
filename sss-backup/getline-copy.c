#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
  /* FILE *fp; */
  char *line = NULL;
  char *token;
  size_t len = sizeof(1024);
  ssize_t read;

  line = malloc(len);

  /* printf("$ "); */
  /* fflush(stdout); */
  while ((read = getline(&line, &len, stdin) != -1))
  /* read = getline(&line, &len, fp); */
  {
    token = strtok(line, " ");
    write(STDOUT_FILENO, token, strlen(token));
    while ((token = strtok(NULL, " ")))
      {
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, token, strlen(token));
      }
  }
  /* free(line); */
  /* free(token); */
  /* exit(EXIT_SUCCESS); */
  return (0);
}
