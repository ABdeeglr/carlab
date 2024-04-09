#include "f_sort.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 1
#include "../head.h"

friend void
printArray(int* array, const int size)
{
    printf("[");
    int backspace_value = 12;
    while (backspace_value * backspace_value < size) backspace_value++;

    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
        if ((i + 1) % backspace_value == 0) printf("\n");
    }

    printf("%d]\n", array[size-1]);
}


friend void
exchange(int* ary, const int index_a, const int index_b)
{
    int tmp = *(ary + index_a);
    *(ary + index_a) = *(ary + index_b);
    *(ary + index_b) = tmp;
}


public void
selectSort(int* a, const int size)
{
    int array_len = size;
    int smallest_index;
    for (int i = 0; i < array_len - 1; i++) {
        printArray(a, 20);
        smallest_index = i;
        for (int j = i + 1; j < array_len; j++)
        {
            if (a[smallest_index] > a[j]) smallest_index = j;
        }
        exchange(a, smallest_index, i);
    }
}
