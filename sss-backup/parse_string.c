#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  /* size_t i = 0; */
  char *str = "My name is john knight";
  char *ptr;
  /* char *str_arr; */


  /* ptr = str; */
  ptr = strtok(str, " ");
  /* str_arr = malloc(sizeof(str)); */
  /* str_arr[i] = *ptr; */
  printf("%lu %s\n", sizeof(str), ptr); 
  /* printf("%i\n", str_arr[i]); */
  /* i++; */
  /* while ((ptr = strtok(NULL, " "))) */
  /* { */
  /*   str_arr = realloc(str_arr, sizeof(str_arr) + sizeof(ptr)); */
  /*   str_arr[i] = *ptr;  */
  /*   printf("%i\n", str_arr[i]); */
  /*   /\* write(1, ptr, strlen(ptr)); *\/ */
  /*   i++; */
  /* } */
     return (0);
}
