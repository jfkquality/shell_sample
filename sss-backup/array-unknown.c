#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *a = 0, n = 0, x, i;

  printf("Enter some numbers, 0 to stop\n");

  a = malloc(sizeof(int));

  while(scanf("%i", &x) && x) {
    /* p = realloc(a, sizeof(int) * (n+1)); */
    /* if(!p) { */
    /*   perror("Out of memory"); */
    /*   free(a); */
    /*   return 1; */
    /* } */
    /* a = p; */

    a[n++] = x;
  }
 
  for(i = 0; i < n; i++) {
    printf("%i\n",  a[i]);
  }

  free(a);

  return 0;
}
