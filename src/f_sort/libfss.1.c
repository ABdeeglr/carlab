/**
 * libfss.h 实现
 * 函数测试库
 * @author ramsay
 * @date 2024.04.10
 */
#include "libfss.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void fSortTest(ArraySorter fs, const int size) {
    int* array = intArrayGenerator(size, size * 10);
    arrayProducterTiming(fs, array, size);
    free(array);
}

bool fSortCertifyTest(ArraySorter fAS, const int __size) {
    int* ary = intArrayGenerator(__size, __size*10);
    int* _ary = (int*) malloc(sizeof(int) * __size);

    fAS(_ary, __size);
    // if (ascendOrderTest() )
    free(_ary);
    free(ary);
    return false;
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