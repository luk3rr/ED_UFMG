#ifndef ANALYZER_H_
#define ANALYZER_H_

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "sort_utils.hh"

#define ROUNDS 10 // Número de testes de ordenação com arrays de tamanho N
#define ARRAY_MAX_SIZE 100000
#define GAP_BETWEEN_ARRAYS 10000
#define ARRAYS_TEST_AMOUNT ARRAY_MAX_SIZE/GAP_BETWEEN_ARRAYS
#define SIN_CICLES 1000000

class Analyzer {
    private:
        static double _timeShellSort[ARRAYS_TEST_AMOUNT][ROUNDS];
        static double _timeHeapSort[ARRAYS_TEST_AMOUNT][ROUNDS];
        static double _timeAverage[ARRAYS_TEST_AMOUNT][3];

        /**
        @brief Função de carga, ou seja, ela é utilizada para aumentar o tempo de execução de outras
        funções, de forma que esse tempo esteja próximo de segundos
        */
        static void dummyTime();

        /**
        @brief Gera um array desordenado de inteiros
        @param size Tamanho do array desejado
        @return Ponteiro para um array desordenado de tamanho 'size'
        */
        static int *randomArray(unsigned int size);

        /**
        @brief Calcula a média dos tempos armazenados no atributo _time
        */
        static void timeAverage();

        /**
        @brief Gera um gráfico de linha com os dados de avaliação armazenados nos atributos desta
        classe
        */
        static void plotAnalysis();

    public:
        /**
        @brief Responsável pela avaliação do tempo de execução dos métodos de ordenação da classe SortUtils
        */
        static void sort_utils_analysis();

};

#endif // ANALYZER_H_
