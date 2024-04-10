#define DEBUG
#include "head.h"
#include "f_sort/f_sort.h"
#include "f_sort/libfss.h"



int main(int argc, const char *argv[]) {

    /* Binary Search Test */

    int* things = intArrayGenerator(20, 100);
    int rp = rand() % 20;
    int value = things[rp];
    printf("Position %d\tValue: %d\n", rp, value);
    selectSort(things, 20);
    printArray(things, 20);
    int pos = binarySearch(things, 20, value);
    printf("Position:%d is %d.\n", (pos == -1 ? pos : pos + 1), value);
    free(things);




    return 0;
}

