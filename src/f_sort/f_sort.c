#include "f_sort.h"
#define DEBUG 0
#include "../head.h"
#include "libfss.h"

void selectSort(int* a, const int size)
{
    int array_len = size;
    int smallest_index;
    for (int i = 0; i < array_len - 1; i++) {
        // printArray(a, 20);
        smallest_index = i;
        for (int j = i + 1; j < array_len; j++)
        {
            if (a[smallest_index] > a[j]) smallest_index = j;
        }
        exchange(a, smallest_index, i);
    }
}


void insertionSort(int* a, const int size) {
    if (size == 1) return;
    if (size == 2) {
        if (a[0] > a[1]) exchange(a, 0, 1);
        return;
    }
    if (a[0] > a[1]) exchange(a, 0, 1);
    for (int i = 2; i < size; i++) {
        int new_position = binarySearch(a, i, a[i]);
        safeInsert(a, size, i, new_position);
    }
}

