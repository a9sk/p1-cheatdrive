#include "selection_sort.h"

void selectionSort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}
