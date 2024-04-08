#define DEBUG
#include "head.h"
#define ARRAY_SIZE 100000
int get_random_integer(int boundary);
int* createIntArray();
void shellSort(int const* a, const int size);
void selectSort(int const* a, const int size);
void insertSort(int const* a, const int size);

int main(int argc, const char *argv[]) {

    



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

/**
 * <p>
 * 首先，找到数组中最小的那个元素，<br>
 * 其次，将它和数组的第一个元素交换位置（如果第一个元素就是最小元素那么它就和自己交换）。<br>
 * 再次，在剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置。<br>
 * 如此往复，直到将整个数组排序。<br>
 * 这种方法叫做选择排序，因为它在不断地选择剩余元素之中的最小者。<br><p/>
 * @param a Comparable Array
 */
void selectSort(int const* a, const int size) {

    // int array_len = size
    // int smallest_index;
    // for (int i = 0; i < array_len - 1; i++)
    // {
    //     smallest_index = i;
    //     for (int j = i + 1; j < array_len; j++)
    //     {
    //         if (a[smallest_index].compareTo(a[j]) <= 0)
    //             continue;
    //         else
    //             smallest_index = j;
    //     }
    //     if (smallest_index != i)
    //         swap(a, smallest_index, i);
    // }
}
