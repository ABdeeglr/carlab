#define DEBUG
#include "head.h"
#include "f_sort/f_sort.h"
#include "f_sort/libfss.h"
#include <threads.h>



int main(int argc, const char *argv[]) {

    printf("进行正确性测试...\n");
    assert(fSortCertifyTest(insertionSort, 100));
    printf("正确性测试通过!\n");
    printf("进行性能分析...\n");
    fSortAnalyzer(insertionSort);
    return 0;
}

