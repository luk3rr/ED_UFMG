#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fat.h"
#include "fib.h"
#include "analisador.h"

int main(int argc, char **argv) {
    // Se houver três argumentos, então uma função especifica e o valor para o cálculo foi passado
    if (argc == 3) {
        char *funcao = argv[1];
        int valor = atoi(argv[2]);

        if (strcmp(funcao, "--r_fat") == 0) {
            printf("%d\n", recursive_fat(valor));
        
        } else if (strcmp(funcao, "--i_fat") == 0) {
            printf("%d\n", iterative_fat(valor));
        
        } else if (strcmp(funcao, "--r_fib") == 0) {
            printf("%d\n", recursive_fib(valor));
        
        } else if (strcmp(funcao, "--i_fib") == 0) {
            printf("%d\n", iterative_fib(valor));

        } else {
            printf("Usage: [--r_fib, --i_fib, --r_fat, --i_fat] <inteiro>");
        }

    // Se houver dois argumentos, então o parametro 'analyzer' foi passado
    } else if (argc == 2) {
        printf("\n>> ANALISE FATORIAL\n");

        struct Analisador fatorial;
        analisar_fat(&fatorial);

        printf("\n>> MATRIZES\n");
        imprimir_matrizes(&fatorial);
        calcular_media(&fatorial);
        calcular_variancia(&fatorial);

        printf("\n>> MEDIAS\n");
        imprimir_medias(&fatorial);

        printf("\n>> VARIANCIAS\n");
        imprimir_variancias(&fatorial);

        printf("-----------------------------------------");
        printf("\n>> ANALISE FIBONACCI\n");

        struct Analisador fibonacci;
        analisar_fib(&fibonacci);

        printf(">> MATRIZES\n");
        imprimir_matrizes(&fibonacci);
        calcular_media(&fibonacci);
        calcular_variancia(&fibonacci);

        printf("\n>> MEDIAS\n");
        imprimir_medias(&fibonacci);

        printf("\n>> VARIANCIAS\n");
        imprimir_variancias(&fibonacci);
        
        plotar_graficos(&fatorial);
        plotar_graficos(&fibonacci);
    
    }
    return 0;
}
