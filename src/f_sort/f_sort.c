#include "f_sort.h"
#define DEBUG 1
#include "../head.h"
#include "libfss.h"

void selectSort(int* a, const int size)
{
    int array_len = size;
    int smallest_index;
    for (int latest = 0; latest < array_len - 1; latest++) {
        // printArray(a, 20);
        smallest_index = latest;
        for (int j = latest + 1; j < array_len; j++)
        {
            if (a[smallest_index] > a[j]) smallest_index = j;
        }
        exchange(a, smallest_index, latest);
    }
}


void insertionSort(int* a, const int size) {
    if (size == 1) return;
    if (size == 2) {
        if (a[0] > a[1]) exchange(a, 0, 1);
        return;
    }

    __DEBUG("Sort start...")
    if (a[0] > a[1]) exchange(a, 0, 1);
    __DEBUG("Basic procedure complete.");

    for (int latest = 2; latest < size; latest++) {
        __DEBUG("Sort doing: round #%d", latest - 1);
        int new_position = ascendingSearch(a, latest, a[latest]);
        safeInsert(a, size, latest, new_position);
        printArray(a, size);
    }
    __DEBUG("Sort Complete.")
}

