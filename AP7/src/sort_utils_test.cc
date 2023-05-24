#include <ctime>
#include <cstdlib>
#include <random>
#include <type_traits>

#include "doctest.h"
#include "sort_utils.hh"

#define ARRAY_MAX_LENGHT_TEST 10000
#define ARRAY_MIN_LENGHT_TEST 100

TEST_CASE("Teste heapsort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    int *array = new int[arrayRandomLength]; // Array que será ordenado
    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        array[i] = i;
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        std::swap(array[i], array[randomPosition]);
    }

    SortUtils::heapSort(array, arrayRandomLength);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (array[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] array;
    delete[] checkArray;

    CHECK(correct);
}

TEST_CASE("Teste heapsort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    int *array = new int[arrayRandomLength]; // Array que será ordenado
    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        array[i] = i;
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        std::swap(array[i], array[randomPosition]);
    }

    SortUtils::shellSort(array, arrayRandomLength);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (array[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] array;
    delete[] checkArray;
    CHECK(correct);
}
