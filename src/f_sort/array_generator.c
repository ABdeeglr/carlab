#include "array_generator.h"

#include <stdlib.h>
#include <time.h>

int* 
intArrayGenerator(const int size, const int boundary) {
    int* numbers = (int*)malloc(sizeof(int) * size);
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
