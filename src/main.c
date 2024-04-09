#define DEBUG
#include "head.h"
#include "f_sort/f_sort.h"
#include <time.h>
#include <locale.h>
#define ARRAY_SIZE 100000
int get_random_integer(int boundary);


int main(int argc, const char *argv[]) {
    
    int* ary = (int*) malloc(sizeof(int) * 20);
    for (int i = 0; i < 20; i++) {
        int temp = get_random_integer(1000);
        printf("%d\t", temp);
        ary[i] = temp;
    }
    puts("");
    printArray(ary, 20);
    selectSort(ary, 20);
    printArray(ary, 20);
    free(ary);

    return 0;
}

int get_random_integer(int boundary) {
    int ret = rand() % boundary;
    return ret;
}


int* createIntArray() {
    Pint numbers = (Pint)malloc(sizeof(int) * ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i += 10)
    {
        numbers[i + 0] = get_random_integer(500000);
        numbers[i + 1] = get_random_integer(500000);
        numbers[i + 2] = get_random_integer(500000);
        numbers[i + 3] = get_random_integer(500000);
        numbers[i + 4] = get_random_integer(500000);
        numbers[i + 5] = get_random_integer(500000);
        numbers[i + 6] = get_random_integer(500000);
        numbers[i + 7] = get_random_integer(500000);
        numbers[i + 8] = get_random_integer(500000);
        numbers[i + 9] = get_random_integer(500000);
    }
    return numbers;
}