#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <stdbool.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
    if (num_arrays == 0) {
        // Return a single element array with 0
        int* result = (int*) malloc(sizeof(int));
        result[0] = 0;
        return result;
    }

    // Determine the total size of all arrays combined
    int total_size = 0;
    for (int i = 0; i < num_arrays; i++) {
        total_size += sizes[i];
    }

    // If the total size is 0, return an array with just the number 0
    if (total_size == 0) {
        int* result = (int*) malloc(sizeof(int));
        result[0] = 0;
        return result;
    }

    // Temporary storage for all values (no need to allocate exactly, as we realloc later)
    int *all_values = (int *)malloc(total_size * sizeof(int));
    int unique_count = 0;

    // Collect unique values
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            bool is_unique = true;
            for (int k = 0; k < unique_count; k++) {
                if (all_values[k] == values[i][j]) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                all_values[unique_count++] = values[i][j];
            }
        }
    }

    // Reallocate to the exact size of unique values
    all_values = (int *)realloc(all_values, unique_count * sizeof(int));

    // Sort the unique values
    mergesort(unique_count, all_values);

    // Create the result array
    int *result = (int *)malloc((unique_count + 1) * sizeof(int));
    result[0] = unique_count;
    for (int i = 0; i < unique_count; i++) {
        result[i + 1] = all_values[i];
    }

    // Free temporary storage
    free(all_values);

    return result;
}
