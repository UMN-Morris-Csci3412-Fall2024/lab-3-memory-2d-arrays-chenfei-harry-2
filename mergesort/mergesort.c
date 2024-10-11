#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void merge(int left[], int right[], int values[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            values[k++] = left[i++];
        } else {
            values[k++] = right[j++];
        }
    }

    while (i < left_size) {
        values[k++] = left[i++];
    }

    while (j < right_size) {
        values[k++] = right[j++];
    }
}

void mergesort(int size, int values[]) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;

    int* left = (int*) calloc(mid, sizeof(int));
    int* right = (int*) calloc(size - mid, sizeof(int));

    for (int i = 0; i < mid; i++) {
        left[i] = values[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = values[i];
    }

    mergesort(mid, left);
    mergesort(size - mid, right);

    merge(left, right, values, mid, size - mid);

    free(left);
    free(right);
}
