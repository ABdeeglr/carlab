#define DEBUG
#include "head.h"
#define ARRAY_SIZE 10000
int get_random_integer(int boundary);

int main(int argc, const char* argv[]) {

    int numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = get_random_integer(50000);
    }
    
    return 0;
}

int get_random_integer(int boundary) {
    int ret = rand() % boundary;
    return ret;
}