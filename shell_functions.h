#ifndef _SHELL_FUNCS
#define _SHELL_FUNCS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* ssize_t _getline(char **lineptr, size_t *n, FILE *stream); */
ssize_t _getline(char *buff);
int getlen(char *s);
void type_prompt();
void sigintHandler(int signum);
void _execute(char *line, char **args, char **envp);
int _printenv(char **env);
char **make_arr(ssize_t read, char *line);
void check_input(ssize_t read, char *line);
char *_getenv(char **env, char *evar);

#endif
