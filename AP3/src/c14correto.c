#include <stdio.h>

int main(void) {
  int n, i, fact = 1;

  printf("Positive integer:");
  scanf("%d", &n);

  if (n < 0) {
    printf("Factorial isn't defined for N < 0");
    return 0;
  }

  for (i = 1; i <= n; i++) {
    fact = fact * i;
  }

  printf("Factorial %d = %d\n", n, fact);

  return 0;
}
