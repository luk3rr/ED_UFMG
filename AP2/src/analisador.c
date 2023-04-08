#include "analisador.h"

// Função responsável por rodar o algoritmo um determinado número de vezes (ROUNDS) dentro de uma mesma faixa de valores (10 <= n < AMOSTRAS)
void analisar_fat(struct Analisador* f) {
    for (int n = 0; n < AMOSTRAS; n++) {
        // Coleta dados sobre o tempo de execução do fatorial recursivo
        for (int i = 0; i <= ROUNDS; i++) {
            getrusage(RUSAGE_SELF, &f->start);
            // fatoriais recursivos de n, T.Q. 10 <= n < AMOSTRAS
            recursive_fat(n + 10);        
            getrusage(RUSAGE_SELF, &f->end);

            f->userTimeRecursive[n][i] = (f->end.ru_utime.tv_sec - f->start.ru_utime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;
            f->sysTimeRecursive[n][i] = (f->end.ru_stime.tv_sec - f->start.ru_stime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;
        }

        // Coleta dados sobre o tempo de execução do fatorial interativo
        for (int i = 0; i <= ROUNDS; i++) {
            getrusage(RUSAGE_SELF, &f->start);
            // fatoriais iterativos de n, T.Q. 10 <= n < AMOSTRAS
            iterative_fat(n + 10);        
            getrusage(RUSAGE_SELF, &f->end);

            f->userTimeIterative[n][i] = (f->end.ru_utime.tv_sec - f->start.ru_utime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;
            f->sysTimeIterative[n][i] = (f->end.ru_stime.tv_sec - f->start.ru_stime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;
        }
    }
}

// Função responsável por rodar o algoritmo um determinado número de vezes (ROUNDS) dentro de uma mesma faixa de valores (10 <= n < AMOSTRAS)
void analisar_fib(struct Analisador* f) {
    for (int n = 0; n < AMOSTRAS; n++) {
        // Coleta dados sobre o tempo de execução do fibonacci recursivo
        for (int i = 0; i <= ROUNDS; i++) {
            getrusage(RUSAGE_SELF, &f->start);
            // fatoriais recursivos de n, T.Q. 10 <= n < AMOSTRAS
            recursive_fib(n + 10);
            getrusage(RUSAGE_SELF, &f->end);

            f->userTimeRecursive[n][i] = (f->end.ru_utime.tv_sec - f->start.ru_utime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;
            f->sysTimeRecursive[n][i] = (f->end.ru_stime.tv_sec - f->start.ru_stime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;
        }

        for (int i = 0; i <= ROUNDS; i++) {
            // Coleta dados sobre o tempo de execução do fibonacci interativo
            getrusage(RUSAGE_SELF, &f->start);
            // fatoriais iterativos de n, T.Q. 10 <= n < AMOSTRAS
            iterative_fib(n + 10);
            getrusage(RUSAGE_SELF, &f->end);

            f->userTimeIterative[n][i] = (f->end.ru_utime.tv_sec - f->start.ru_utime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;
            f->sysTimeIterative[n][i] = (f->end.ru_stime.tv_sec - f->start.ru_stime.tv_sec) + (f->end.ru_utime.tv_usec - f->start.ru_utime.tv_usec) / 1000000.0;        
        }
    }
}

// Média dos tempos de execução do fatorial/fibonacci de um mesmo número
void calcular_media(struct Analisador* f) {
    // Calcula a média dos tempos iterativo
    for (int l = 0; l < AMOSTRAS; l++) {
        double soma = 0;
        for (int c = 0; c < ROUNDS; c++) {
            soma += f->userTimeIterative[l][c];
        }

        f->mediasIterative[l] = soma / ROUNDS;
    }

    // Calcula a média dos tempos recursivo
    for (int l = 0; l < AMOSTRAS; l++) {
        double soma = 0;
        for (int c = 0; c < ROUNDS; c++) {
            soma += f->userTimeRecursive[l][c];
        }

        f->mediasRecursive[l] = soma / ROUNDS;
    }
}

// A variância é utilizada para verificar se os tempos de execução do fatorial/fibonacci de um mesmo número estão discrepantes
void calcular_variancia(struct Analisador* f) {
    calcular_media(f);
    // Calcula variancia dos tempos de execução interativo
    for (int l = 0; l < AMOSTRAS; l++) {
        double variancia = 0;
        for (int c = 0; c < ROUNDS; c++) {
            variancia += pow(f->userTimeIterative[l][c] - f->mediasIterative[l], 2);
        }
        f->varianciasIterative[l] = variancia / (ROUNDS - 1);
    }

    // Calcula variancia dos tempos de execução recursivo
    for (int l = 0; l < AMOSTRAS; l++) {
        double variancia = 0;
        for (int c = 0; c < ROUNDS; c++) {
            variancia += pow(f->userTimeRecursive[l][c] - f->mediasRecursive[l], 2);
        }
        f->varianciasRecursive[l] = variancia / (ROUNDS - 1);
    }
}

void imprimir_matrizes(struct Analisador* f) {
    // Matriz de tempos de execução algoritmos recursivos
    printf("\n>> Matriz de tempos de execução algoritmo recursivo\n");
    for (int l = 0; l < AMOSTRAS; l++) {
        printf("%d | ", l + 10);
        for (int c = 0; c <= ROUNDS; c++) {
            printf("%lf ", f->userTimeRecursive[l][c]); 
        }
        printf("\n");
    }
    // Matriz de tempos de execução algoritmos iterativo
    printf("\n>> Matriz de tempos de execução algoritmo iterativo\n");
    for (int l = 0; l < AMOSTRAS; l++) {
        printf("%d | ", l + 10);
        for (int c = 0; c <= ROUNDS; c++) {
            printf("%lf ", f->userTimeIterative[l][c]); 
        }
        printf("\n");
    }
}

void imprimir_medias(struct Analisador* f) {
    printf("\n>> Medias recursivo\n");
    for (int c = 0; c < AMOSTRAS; c++) {
        printf("%d | %lf\n", c + 10, f->mediasRecursive[c]); 
    }

    printf("\n>> Medias iterativo\n");
    for (int c = 0; c < AMOSTRAS; c++) {
        printf("%d | %lf\n", c + 10, f->mediasIterative[c]); 
    }
    printf("\n");
}

void imprimir_variancias(struct Analisador* f) {
    printf("\n>> Variâncias recursivo\n");
    for (int c = 0; c < AMOSTRAS; c++) {
        printf("%d | %lf\n", c + 10, f->varianciasRecursive[c]); 
    }

    printf("\n>> Variâncias iterativo\n");
    for (int c = 0; c < AMOSTRAS; c++) {
        printf("%d | %lf\n", c + 10,  f->varianciasIterative[c]); 
    }
    printf("\n");
}

// Função utilizada apenas pra testar como plotar um gráfico
void plotar_graficos(struct Analisador* f) {
    // Grafico medias algoritmo recursivo
    FILE *dados_recursivos = fopen("dados_recursivos.dat", "w");
    for (int i = 0; i < AMOSTRAS; i++) {
        fprintf(dados_recursivos, "%d %lf\n", i + 10, f->mediasRecursive[i]);
    }
    fclose(dados_recursivos);

    // Chama o GNUplot para plotar o gráfico
    FILE *gnuplot1 = popen("gnuplot -persist", "w");
    fprintf(gnuplot1, "set title 'Gráfico médias durações'\n");
    fprintf(gnuplot1, "set xlabel 'Médias'\n");
    fprintf(gnuplot1, "set ylabel 'Tempo em segundos'\n");
    fprintf(gnuplot1, "set style fill solid\n");
    fprintf(gnuplot1, "set style line 1 lc rgb 'blue'\n");
    fprintf(gnuplot1, "plot 'dados_recursivos.dat' using 1:2 with lines linestyle 1\n");
    pclose(gnuplot1);
}
