/*
 * week4_1_dynamic_array.c
 * Description:
 *   Creates a dynamic integer array using malloc, reads values,
 *   calculates their sum and average, and frees allocated memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;
    int sum = 0;
    double average;

    printf("Enter number of elements: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    /* Allocate memory for n integers. */
    arr = malloc(n * sizeof(int));

    /* Check whether memory allocation was successful. */
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);

    /* Read all integers into the dynamic array. */
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }

        sum += arr[i];
    }

    /* Calculate the average using floating-point arithmetic. */
    average = (double)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    /* Free dynamically allocated memory. */
    free(arr);

    return 0;
}
