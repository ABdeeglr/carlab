#define DEBUG
#include "head.h"
#include "f_sort/f_sort.h"
#include "f_sort/array_generator.h"



int main(int argc, const char *argv[]) {

    const int SIZE = 16;
    int* ars = intArrayGenerator(SIZE, SIZE*10);
    printArray(ars, SIZE);
    selectSort(ars, SIZE);
    printf("Making array ordered...\n");
    printArray(ars, SIZE);
    int random_target = rand() % (SIZE * 10);
    printf("Searching %d for best place.\n", random_target);
    int pos = binarySearch(ars, SIZE, random_target);
    printf("Position: %d will be insert for %d.\n", pos, random_target);
    free(ars);




    return 0;
}

