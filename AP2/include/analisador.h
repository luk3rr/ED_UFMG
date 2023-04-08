#ifndef ANALISADOR
#define ANALISADOR

#include <time.h>
#include <stdio.h>
#include <sys/resource.h>

#include "fib.h"
#include "fat.h"

// Número de vezes que o tempo de execução de um fatorial/fibonacci de um mesmo número N será armazenada
#define ROUNDS 5

// Defini a faixa de valores que será testada. Essa faixa é 10 <= n < AMOSTRAS + 10.
#define AMOSTRAS 6 

typedef struct Analisador {
      double varianciasRecursive[5], varianciasIterative[5];
      double mediasRecursive[5], mediasIterative[5];
      double userTimeRecursive[5][ROUNDS], userTimeIterative[5][ROUNDS];
      double sysTimeRecursive[5][ROUNDS], sysTimeIterative[5][ROUNDS];
      struct rusage start, end;
} Analisador;

void calcular_variancia(struct Analisador* a);
void calcular_media(struct Analisador* a);

void imprimir_matrizes(struct Analisador* a);
void imprimir_medias(struct Analisador* a);
void imprimir_variancias(struct Analisador* a);

void analisar_fib(struct Analisador* a);
void analisar_fat(struct Analisador* a);

void plotar_graficos(struct Analisador* a);

#endif
