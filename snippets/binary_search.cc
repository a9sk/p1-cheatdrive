#include "binary_search.h"

int binarySearchRecursive(const int array[], int startIndex, int endIndex, int number) {
    if (startIndex > endIndex) {
        return -1;
    }

    int mid = startIndex + (endIndex - startIndex) / 2;

    if (array[mid] == number) {
        return mid;
    } else if (array[mid] > number) {
        return binarySearchRecursive(array, startIndex, mid - 1, number);
    } else {
        return binarySearchRecursive(array, mid + 1, endIndex, number);
    }
}

int binarySearchArrayRecursive(const int array[], int length, int number) {
    return binarySearchRecursive(array, 0, length - 1, number);
}

int binarySearchIterative(const int array[], int length, int number) {
    int startIndex = 0;
    int endIndex = length - 1;

    while (startIndex <= endIndex) {
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (array[mid] == number) {
            return mid;
        } else if (array[mid] < number) {
            startIndex = mid + 1;
        } else {
            endIndex = mid - 1;
        }
    }

    return -1;
}
