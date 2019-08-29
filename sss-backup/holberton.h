#ifndef _SHELL_FUNCS
#define _SHELL_FUNCS

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int getlen(char *s);
void type_prompt();
void sigintHandler(int signum);
void _execute(char *line, char **args, char **envp);
int _printenv(char **env);
char **make_arr(ssize_t read, char *line);
void check_input(ssize_t read, char *line);

char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strpbrk(char *s, char *accept);
unsigned int _strspn(char *s, char *accept);
char *_strstr(char *haystack, char *needle);

#endif
