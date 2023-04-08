#include <stdlib.h>
#include <stdio.h>

#define UM_MILHAO 1000000

// Se der mole esse trem aqui agacha seu computador kkkkkkkkkkkkkk
int main(void) {
  int *p;
  int i=0;
  while (1) {
    p = malloc(128);
    printf("%ld\n", (long)p);
    free(p);
    i++;
    if (i > UM_MILHAO) break;
  }
  return (0);
}
