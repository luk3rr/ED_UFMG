#include "fat.h"

#define DEZ_MILHOES 10000000

unsigned int recursive_fat(int n) {
    if (n == 0)
        return 1;

    else {
        // Carga utilizada para aumentar o tempo de execução do algoritmo, de forma que facilite a análise
        for (int i = 0; i < DEZ_MILHOES; i++) { float k = sin(1); }
        return n * recursive_fat(n - 1);
    }
}

unsigned int iterative_fat(int n) {
    unsigned int f = 1;
    for (int i = n; i > 0; i--) {
        // Carga utilizada para aumentar o tempo de execução do algoritmo, de forma que facilite a análise
        for (int i = 0; i < DEZ_MILHOES; i++) { float k = sin(1); }
        f = f * n;
        n = n - 1;
    }
    return f;
}
