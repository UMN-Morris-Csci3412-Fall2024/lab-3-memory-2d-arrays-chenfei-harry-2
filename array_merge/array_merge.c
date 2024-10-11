#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <stdbool.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
    int *unique_values = (int *)malloc(1000 * sizeof(int));
    if (unique_values == NULL) {
        return NULL;
    }

    int unique_count = 0;

    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            bool is_unique = true;
            for (int k = 0; k < unique_count; k++) {
                if (unique_values[k] == values[i][j]) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                unique_values[unique_count++] = values[i][j];
            }
        }
    }

    unique_values = (int *)realloc(unique_values, unique_count * sizeof(int));
    if (unique_values == NULL) {
        return NULL;
    }

    mergesort(unique_count, unique_values);

    int *result = (int *)malloc((unique_count + 1) * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    result[0] = unique_count;
    for (int i = 0; i < unique_count; i++) {
        result[i + 1] = unique_values[i];
    }

    free(unique_values);

    return result;
}
