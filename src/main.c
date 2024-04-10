#define DEBUG
#include "head.h"
#include "f_sort/f_sort.h"
#include "f_sort/libfss.h"



int main(int argc, const char *argv[]) {

    const int size = 15;
    int* things = intArrayGenerator(size, 100);
    
    selectSort(things, size);
    int ran = rand() % 90;
    printf("Search correct position for %d", ran);
    printf(" in Array:\n\t");
    printArray(things, size);
    printf("The qualified position is %dnd.\n", ascendingSearch(things, size, ran) + 1);

    free(things);






    return 0;
}

