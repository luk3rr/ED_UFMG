#include "fib.h"

#define DEZ_MILHOES 10000000

unsigned int recursive_fib(int n) {
    if (n < 3) return 1;
    
    else {
        // Carga utilizada para aumentar o tempo de execução do algoritmo, de forma que facilite a análise
        for (int i = 0; i < DEZ_MILHOES; i++) { float k = sin(1); }
        return recursive_fib(n - 1) + recursive_fib(n - 2);
    }
}

unsigned int iterative_fib(int n) {
    int fb1 = 1, fb2 = 1;
	unsigned int fb;

    if (n < 3) return 1;

    for (int i = 3; i <= n; i++) { 
        // Carga utilizada para aumentar o tempo de execução do algoritmo, de forma que facilite a análise
        for (int i = 0; i < DEZ_MILHOES; i++) { float k = sin(1); }
        fb = fb2 + fb1;
        fb2 = fb1;
        fb1 = fb;  
    } 
   return fb;
}
