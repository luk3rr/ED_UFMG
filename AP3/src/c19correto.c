#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// utilizo uint64_t, pois o maior inteiro que esse tipo armazena tem 19 casas decimais, o suficiente
// para armazenar o valor da soma no pior caso especificado adiante.
uint64_t sum_to_n_gauss(int num) {
  return ((uint64_t)num * (num + 1))/2;
}

void printSum() {
  // 4 caracteres para 'sum=' e 18 caracteres para o maior inteiro que a função sum_to_n retorna, 1 caractere para o caractere nulo
  char *buf = malloc(sizeof(char) * 23);
  char line[10];

  printf("enter a number:\n");

  // o maior número que 'line' armazena é 999.999.999, pois o caractere da última posição é utilizado
  // pelo caractere nulo
  // no pior caso, de o número inserido ser esse, a função sum_to_n retorna um número de 18 casas decimais
  fgets(line, 10, stdin);
  int num = atoi(line);
  sprintf(buf, "sum=%zu", sum_to_n_gauss(num));

  printf("%s\n", buf);
  free(buf);
}

int main(void) {
  printSum();
  return 0;
}
