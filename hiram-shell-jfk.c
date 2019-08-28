#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void what_next_loop(void)
{
  char *str, *token;
  //int status;
  while(str)
    {
      printf("($) \n");
      *str = readstr();
      *token = *tokenizer(str);
      //status = executor(token);
      free(str);
      free(token);
    }
}
char *_getline(char **lineptr, ssize_t *n, int stream)
{
  char *str;
  *str = read(stream, *lineptr, *n);
  return (str);
}
char *readstr(void)
{
  char *str = NULL;
  ssize_t buff = 1024;
  _getline(&str, &buff, STDIN_FILENO);
  return (str);
}
char **tokenizer(char *str)
{
  char *token;
  char **tokens;
  int buff = sizeof(1024);
  int position = 0;
  *tokens = malloc(buff);
  if(!tokens)
    {
      fprintf(stderr, "allocation error\n");
      exit(EXIT_FAILURE);
    }
  token = strtok(str, " ");
  while(token != NULL)
    {
      tokens[position] = token;
      position++;
      if(position >= buff)
	{
	  buff += buff;
	  tokens = realloc(tokens, sizeof(buff));
	  if(!tokens)
	    {
	      fprintf(stderr, "allocation error\n");
	      exit(EXIT_FAILURE);
	    }
	}
      token = strtok(NULL, " ");
    }
  tokens[position] = NULL;
  return(tokens);
}
int main(void)
{
  //configurations?
  what_next_loop();
  //cleanup> free(what_next_loop)?
  return (EXIT_SUCCESS);
}
