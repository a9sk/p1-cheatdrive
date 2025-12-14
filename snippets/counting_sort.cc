#include "counting_sort.h"

void countingSort(int array[], int length) {
    if (length <= 0) return;

    int maxVal = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    int* count = new int[maxVal + 1];
    for (int i = 0; i <= maxVal; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        count[array[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}
