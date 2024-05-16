/**
 * Practice Problem 2.11
*/

#include <stdio.h>

#define ARRAY_SIZE 5

void inplace_swap(int *x, int *y) {
    *y ^= *x;
    *x ^= *y;
    *y ^= *x;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt-1; first < last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}

int main() {
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5};

    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        printf(" %d", arr[i]);
    printf("\n");

    reverse_array(arr, ARRAY_SIZE);

    for (i = 0; i < ARRAY_SIZE; i++)
        printf(" %d", arr[i]);
    printf("\n");

    return 0;
}