#include "libfss.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* array, const int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size-1]);
}

bool safeInsert(int* array, const int array_size,
    const int ori_position, const int new_position)
{
    if (ori_position > array_size) return false;
    if (new_position > array_size) return false;

    if (new_position < ori_position) {
        int tmp = array[ori_position];
        for (int i = ori_position; i > new_position; i--) {
            array[i] = array[i - 1];
        }
        array[new_position] = tmp;
    }
    else {
        int tmp = array[ori_position];
        for (int i = ori_position; i < new_position; i++) {
            array[i] = array[i + 1];
        }
        array[new_position] = tmp;
    }

    return true;
}

void exchange(int* ary, const int index_a, const int index_b)
{
    int tmp = *(ary + index_a);
    *(ary + index_a) = *(ary + index_b);
    *(ary + index_b) = tmp;
}

int* intArrayGenerator(const int size, const int boundary) {
    int* numbers = (int*)malloc(sizeof(int) * size);
    srand((unsigned) time(NULL));

    if (size % 10 != 0) {
        for (int i = 0; i < size; i++) numbers[i] = rand() % boundary;
        return numbers;
    }
    
    for (int i = 0; i < size; i += 10)
    {
        numbers[i + 0] = rand() % boundary;
        numbers[i + 1] = rand() % boundary;
        numbers[i + 2] = rand() % boundary;
        numbers[i + 3] = rand() % boundary;
        numbers[i + 4] = rand() % boundary;
        numbers[i + 5] = rand() % boundary;
        numbers[i + 6] = rand() % boundary;
        numbers[i + 7] = rand() % boundary;
        numbers[i + 8] = rand() % boundary;
        numbers[i + 9] = rand() % boundary;
    }
    return numbers;
}

void fSortTimeTest(f_sort fs, const int size) {
    int* array = intArrayGenerator(size, size * 10);
    printArray(array, size);
    clock_t start = clock();
    fs(array, size);
    clock_t end = clock();
    clock_t diff = end - start;
    printf("last: %lu\n", diff);
    printArray(array, size);
    free(array);
}

bool fSortCertifyTest(f_sort fs, const int __size) {
    return false;
}

int binarySearch(int* ascending_array, const int __size, const int __value) {
    int start = 0;
    int end = __size;
    int interval = (end - start) / 2;

    while (ascending_array[interval] != __value) {
        if (ascending_array[interval] > __value) end = interval;
        else if (ascending_array[interval] < __value) start = interval;
        else return interval;
        interval = (end - start) / 2;
    }

    return -1;
}
