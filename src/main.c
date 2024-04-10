#define DEBUG
#include "head.h"
#include "f_sort/f_sort.h"
#include "f_sort/libfss.h"



int main(int argc, const char *argv[]) {

    // fSortTest(insertionSort, 30);
    int* p = intArrayGenerator(30, 300);
    printArray(p, 30);
    insertionSort(p, 30);
    printArray(p, 30);
    free(p);






    return 0;
}

