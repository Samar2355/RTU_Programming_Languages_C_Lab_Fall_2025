/*
 * week4_1_dynamic_array.c
 * Author: Samar Joshi
 * Student ID: 241ADB043
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int array_sum(int arr[], int size);
float array_avg(int arr[], int size);

int main(void) {
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Allocate memory for n integers using calloc
    arr = (int*)calloc(n, sizeof(int));

    // Check allocation success
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    } else {
        printf("Memory successfully allocated.\n");
    }

    // Read n integers from user input and store in array
    for (int j = 0; j < n; ++j) {
        printf("Enter element %d: ", j + 1);
        scanf("%d", &arr[j]);
    }
    // Compute sum and average
    int array_sum(int arr[], int size) {
    int my_sum = 0;
    for (int i = 0; i < size; i++) {
        my_sum += arr[i];
    }
    return my_sum; 
}

float array_avg(int arr[], int size) {
    return (float)array_sum(arr, size) / size;
}

    // Print the results
    printf("Sum: %d\n", array_sum(arr, n));
    printf("Avg: %.2f\n", array_avg(arr, n));

    // Free allocated memory
    free(arr);

    return 0;
}


