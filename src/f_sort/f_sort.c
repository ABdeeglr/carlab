#include "f_sort.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 0
#include "../head.h"
#include <time.h>
#include "array_generator.h"

friend void
printArray(int* array, const int size)
{
    // if (size < 20) {
    //     printf("[");
    //     for (int i = 0; i < size - 1; i++) printf("%d, ", i);
    //     printf("19]\n");
    // }

    printf("[");
    // int backspace_value = 12;
    // while (backspace_value * backspace_value < size) backspace_value++;

    
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
        // if ((i + 1) % backspace_value == 0) printf("\n");
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


/**
 * 将数组中的指定元素插入指定位置，原本处在该位置的元素向后移动一位，以此类推。 
 * 从而保持数组原本的顺序。 
 * @param array_size 数组长度
 * @param ori_position 需要被移动的数组元素的初始位置
 * @param new_position 需要被移动的数组元素的目标位置
 * @return true: 插入成功
 * @return false: 插入失败
 */
private bool
safeInsert(int* array, const int array_size,
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

public void
selectSort(int* a, const int size)
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


public void
insertionSort(int* a, const int size) {
    for (int i = 1; i < size; i++) {
        int new_position = 0;

        for (int j = 0; j < i; j++) {
        }
    }
}

private int
binarySearch(int* asceding_array, const int size, const int value)
{
    int start = 0;
    int end = size - 1;

    while (end - start > 1) {
        int internal = (end + start) / 2;
        printf("Start:%d, Internal:%d, End:%d.\n", start, internal, end);
        if (asceding_array[internal] < value) start = internal;
        else if (asceding_array[internal] > value) end = internal;
        else return internal;
    }
    
    return start + 1;
}


public void
fSortTest(f_sort fs, const int size) {
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
