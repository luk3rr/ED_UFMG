#include "analyzer.hh"

double Analyzer::_timeShellSort[ARRAYS_TEST_AMOUNT][ROUNDS];
double Analyzer::_timeHeapSort[ARRAYS_TEST_AMOUNT][ROUNDS];
double Analyzer::_timeAverage[ARRAYS_TEST_AMOUNT][3];

void Analyzer::dummyTime() {
    volatile int __attribute__((unused)) dummy;
    for (int i = 0; i < SIN_CICLES; i++)
        dummy = sin(1);
}

int *Analyzer::randomArray(unsigned int size) {
    int randomPosition;
    int *array = new int[size];

    // Preenche o array
    for (unsigned int i = 0; i < size; i++) {
        array[i] = i;
    }

    // Embaralha os números do array
    for (int i = size - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        std::swap(array[i], array[randomPosition]);
    }

    return array;
}

void Analyzer::timeAverage() {
    std::cout << "Calculando tempos médios de execução..." << std::endl;

    double sum;

    for (int i = 0; i < ARRAYS_TEST_AMOUNT; i++) {
        sum = 0;

        for (int j = 0; j < ROUNDS; j++) {
            sum += Analyzer::_timeShellSort[i][j];
        }

        Analyzer::_timeAverage[i][0] = GAP_BETWEEN_ARRAYS * (i + 1);
        Analyzer::_timeAverage[i][1] = sum / ROUNDS;
    }

    for (int i = 0; i < ARRAYS_TEST_AMOUNT; i++) {
        sum = 0;

        for (int j = 0; j < ROUNDS; j++) {
            sum += Analyzer::_timeHeapSort[i][j];
        }

        Analyzer::_timeAverage[i][2] = sum / ROUNDS;
    }
}

void Analyzer::plotAnalysis() {
    Analyzer::timeAverage();

    std::ofstream data("data.dat");
    std::cout << "Organizando dados..." << std::endl;

    for (int i = 0; i < ARRAYS_TEST_AMOUNT; i++) {
        // TAMANHO_ARRAY - MEDIA_TEMPO_SHELLSORT - MEDIA_TEMPO_HEAPSORT
        data << Analyzer::_timeAverage[i][0] / 1000 << " "
             << Analyzer::_timeAverage[i][1] << " "
             << Analyzer::_timeAverage[i][2] << " "
             << std::endl;
    }

    data.close();

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Tempo execução algoritmos de ordenação'\n");
        fprintf(gnuplotPipe, "set xlabel 'Tamanho do array em milhares'\n");
        fprintf(gnuplotPipe, "set ylabel 'Tempo de ordenação (s)'\n");
        fprintf(gnuplotPipe, "set terminal png\n");
        fprintf(gnuplotPipe, "set output 'grafico.png'\n");
        fprintf(gnuplotPipe, "plot 'data.dat' using 1:2 with lines title 'ShellSort', 'data.dat' using 1:3 with lines title 'HeapSort'\n");
        fflush(gnuplotPipe);
        pclose(gnuplotPipe);

        std::cout << "Gráfico gerado" << std::endl;
    }
    else {
        std::cerr << "ERRO ao executar o gnuplot" << std::endl;
    }
}

void Analyzer::sort_utils_analysis() {
    int *array;
    unsigned int arraySize;

    std::cout << "Testando shellsort..." << std::endl;
    for (int i = 0; i < ARRAYS_TEST_AMOUNT; i++) {
        arraySize = GAP_BETWEEN_ARRAYS * (i + 1);
        std::cout << "\rTamanho do array: " << arraySize << std::flush;

        for (int j = 0; j < ROUNDS; j++) {
            array = Analyzer::randomArray(arraySize);

            auto start = std::chrono::high_resolution_clock::now();

            Analyzer::dummyTime();
            SortUtils::shellSort(array, arraySize);
            Analyzer::dummyTime();

            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            Analyzer::_timeShellSort[i][j] = time.count(); // Tempo em segundos
            delete[] array;
        }
    }

    std::cout << std::endl;

    std::cout << "Testando heapsort..." << std::endl;
    for (int i = 0; i <= ARRAYS_TEST_AMOUNT; i++) {
        arraySize = GAP_BETWEEN_ARRAYS * i;
        std::cout << "\rTamanho do array: " << arraySize << std::flush;

        for (int j = 0; j < ROUNDS; j++) {
            array = Analyzer::randomArray(arraySize);

            auto start = std::chrono::high_resolution_clock::now();

            Analyzer::dummyTime();
            SortUtils::heapSort(array, arraySize);
            Analyzer::dummyTime();

            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            Analyzer::_timeHeapSort[i][j] = time.count(); // Tempo em segundos
            delete[] array;
        }
    }

    std::cout << std::endl;

    Analyzer::plotAnalysis();
}
