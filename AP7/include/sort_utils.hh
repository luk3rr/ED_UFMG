#ifndef SORT_UTILS_H_
#define SORT_UTILS_H_

#include <type_traits>
#include <numbers>
#include <cmath>

class SortUtils {
    private:
        static void maxHeapify(int array[], unsigned int position, unsigned int size);

        static void buildMaxHeap(int array[], unsigned int size);

    public:
        static void heapSort(int array[], unsigned int size);

        static void shellSort(int array[], unsigned int size);
};

#endif // SORT_UTILS_H_
