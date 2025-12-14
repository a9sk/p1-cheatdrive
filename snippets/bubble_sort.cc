#include "bubble_sort.h"

void bubbleSort(int array[], int length) {
    bool swapped;

    for (int i = 0; i < length - 1; i++) {
        swapped = false;

        for (int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            return;
        }
    }
}
