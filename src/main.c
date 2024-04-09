#define DEBUG
#include "head.h"
#include "f_sort/f_sort.h"
#include <time.h>

int* createIntArray(const int size, const int boundary); 

int main(int argc, const char *argv[]) {
    Pint sb = createIntArray(20, 100);
    printArray(sb, 20);
    free(sb);

    
    return 0;
}


int* createIntArray(const int size, const int boundary) {
    Pint numbers = (Pint)malloc(sizeof(int) * size);
    srand((unsigned) time(NULL));

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
