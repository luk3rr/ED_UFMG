#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int i;
  int a[10];
  for (i = 0; i < 9; i++)
    a[i] = i;
  int n = i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
