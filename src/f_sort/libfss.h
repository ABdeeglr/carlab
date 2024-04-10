/**
 * LIBFSS: library of support fuction and macros for f_sort
*/

#ifndef __LIBFSS__
#define __LIBFSS__

#include <stdbool.h>

/*****  Macro  ******/

/**
 * 对外接口
 */ 
#define public

/**
 * 仅限编译单元内使用
 */
#define private 

/**
 * 项目内使用
 */
#define friend


typedef void (*ArraySorter)(int*, const int);
typedef ArraySorter ArrayProducter;

/**********  Support Fuctions  **********/

/**
 * (finished-tested) reverseArray
 * 翻转数组
 */
void reverseArray(int* __array, const int __size);

/**
 * (finished-pass) Print the array in human-readable style
 */
void printArray(int* __array, const int __size);

/**
 * (finished-pass) 在内存上开辟一个数列，需要回收
 */
int* intArrayGenerator(const int size, const int boundary);

/**
 * (finished-untested) 将数组中的指定元素插入指定位置，原本处在该位置的元素向后移动一位，以此类推。 
 * 从而保持数组原本的顺序。 
 * @param array_size 数组长度
 * @param ori_position 需要被移动的数组元素的初始位置
 * @param new_position 需要被移动的数组元素的目标位置
 * @return true: 插入成功
 * @return false: 插入失败
 * 
 */
bool safeInsert(int* array, const int array_size, const int ori_position, const int new_position);

/**
 * (finished-pass) 交换数组中的两个位置上的元素
 */
void exchange(int* ary, const int index_a, const int index_b);


/**
 * (unfinish) ascedingSearch.
 * 在有序数组中寻找一个合适的位置，使得插入新元素后，仍能保持有序
 */
int ascendingSearch(int* asceding_array, const int size, const int value);


/**
 * (edfinish-tested) binarySearch
 * 在有序数组中，查找一个元素的位置，并返回第一个匹配的位置
 * 如果不存在，则返回 -1
 */
int binarySearch(int* ascending_array, const int __size, const int __value);


/**
 * (finish-pass) arrayProducterTiming
 * 针对任意符合 ArrayProducter 或 ArraySorter 接口的函数进行测试
 * 统计其占用的 CPU 时间片。
 * 返回所使用的时间。
*/
long arrayProducterTiming(ArrayProducter ap, int* __array, const int __size);


/*********  Test  ***********/



/**
 * (unfinish-backtime) fSortTimeTest
 * 排序函数测试函数. 
 * 根据输入的排序函数和需要的数组大小，自动进行测试
 * @param fs 特定的排序函数
 * @param size 作为测试对象的数组长度
*/
void fSortTimeTest(ArraySorter fs, const int __size);


/**
 * (unfinish) fSortCertifyTest
 * 排序函数正确性测试，通过返回 true，反之返回 false
 */
bool fSortCertifyTest(ArraySorter fs, const int __size);


/**
 * (finished-pass) ascendOrderTest
 * 测试数组是否有序
 */
bool ascendOrderTest(int* __array, const int __size);


#endif