#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fat.h"
#include "fib.h"

int main(int agrc, char **argv) {
    
    char *funcao = argv[1];
    int valor = atoi(argv[2]);

    if (strcmp(funcao, "--r_fat") == 0) {
        printf("%llu\n", recursive_fat(valor));
    
    } else if (strcmp(funcao, "--i_fat") == 0) {
        printf("%llu\n", interative_fat(valor));
    
    } else if (strcmp(funcao, "--r_fib") == 0) {
        printf("%llu\n", recursive_fib(valor));
    
    } else if (strcmp(funcao, "--i_fib") == 0) {
        printf("%llu\n", interative_fib(valor));
    
    } else {
        printf("Usage: [--r_fib, --i_fib, --r_fat, --i_fat] <inteiro>");
    }

    return 0;
}
