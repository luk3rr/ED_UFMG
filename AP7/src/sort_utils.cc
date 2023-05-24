#include "sort_utils.hh"

void SortUtils::maxHeapify(int array[], unsigned int position, unsigned int size) {
    unsigned int largest = position;
    unsigned int left = 2 * position + 1;
    unsigned int right = 2 * position + 2;

    if (left < size and array[left] > array[largest])
        largest = left;

    if (right < size and array[right] > array[largest])
        largest = right;

    if (largest != position) {
        std::swap(array[position], array[largest]);
        SortUtils::maxHeapify(array, largest, size);
    }
}

void SortUtils::buildMaxHeap(int array[], unsigned int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        SortUtils::maxHeapify(array, i, size);
    }
}

void SortUtils::heapSort(int array[], unsigned int size) {
    SortUtils::buildMaxHeap(array, size);

    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        SortUtils::maxHeapify(array, 0, i);
    }
}

void SortUtils::shellSort(int array[], unsigned int size) {
    unsigned int h = 1;
    unsigned int j;
    unsigned int operacoes = 0;

    while (h < size / std::numbers::phi) {
        h = std::ceil(h * std::numbers::phi);
    }

    while (h >= 1) {
        for (unsigned int i = h; i < size; i++) {
            j = i;
            while (j >= h and array[j - h] > array[j]) {
                operacoes++;
                std::swap(array[j], array[j - h]);
                j -= h;
            }
        }
        h = std::floor(h / std::numbers::phi);
    }
}
