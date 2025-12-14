#include <iostream>
#include "sequential_search.h"

int sequentialSearch(const int array[], int length, int number) {
    for (int i = 0; i < length; i++) {
        if (array[i] == number) {
            return i;
        }
    }
    return -1;
}
