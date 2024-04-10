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

void fSortTest(ArraySorter fs, const int size) {
    int* array = intArrayGenerator(size, size * 10);
    arrayProducterTiming(fs, array, size);
    free(array);
}

bool fSortCertifyTest(ArraySorter fs, const int __size) {
    return false;
}

int binarySearch(int* ascending_array, const int __size, const int __value) {
    int start = 0;
    int end = __size;
    int interval = (end + start) / 2;

    while (end - start > 1) {
        if (ascending_array[interval] > __value) end = interval;
        else if (ascending_array[interval] < __value) start = interval;
        else break;
        interval = (end + start) / 2;
    }

    if (ascending_array[interval] == __value) {
        while (ascending_array[interval - 1] == __value)
        {
            interval--;
        }
        return interval;
    }
    else return -1;
}


bool ascendOrderTest(int* __array, const int __array_size) {
    if (__array_size <= 1) return true;
    for (int i = 0; i < __array_size - 1; i++) {
        if (__array[i] <= __array[i+1]) continue;
        else return false;
    }
    return true;
}

void reverseArray(int* __array, const int __size) {
    int* tmp = (int*) malloc(sizeof(int) * __size);
    for (int i = 0; i < __size; i++) {
        tmp[i] = __array[__size - 1 - i];
    }
    for (int i = 0; i < __size; i++) {
        __array[i] = tmp[i];
    }
    free(tmp);
}


long arrayProducterTiming(ArrayProducter ap, int* __array, const int __size) {
    printArray(__array, __size);
    clock_t start = clock();
    ap(__array, __size);
    clock_t end = clock();
    clock_t diff = end - start;
    printf("last: %lu\n", diff);
    printArray(__array, __size);
    return (long) diff;
}