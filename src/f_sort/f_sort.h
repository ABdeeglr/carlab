/**
 * f_sort.h: A function collection about sort methods:
 * shell sort, bubble sort, insertion sort, selectiong sort, and so on...
 * @author : ABdeeglr Trueco
 * @machine: frieren@trueco
 * @date   : 2024.04.08
 * @email  : abdeeglr@icloud.com
 */
#ifndef __F_SORT_H__
#define __F_SORT_H__

// #include <stdbool.h>

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

// A self-designede compare function for any object
typedef int (*f_compare)(void* a, void* b);

// int sort function interface
typedef void (*f_sort)(int*, const int);


friend int* createIntArray();

friend int natural_compare(int a, int b);

friend void exchange(int* ary, const int index_a, const int index_b);

friend void printArray(int* array, const int size);


/**
 * 首先，找到数组中最小的那个元素. 
 * 其次，将它和数组的第一个元素交换位置（如果第一个元素就是最小元素那么它就和自己交换）. 
 * 再次，在剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置. 
 * 如此往复，直到将整个数组排序. 
 * 这种方法叫做选择排序，因为它在不断地选择剩余元素之中的最小者. 
 * @param a Comparable Array
 */
public void selectSort(int* a, const int size);

/**
 * 插入排序 
 * 
 * 每次排序一个子数组和一个新的元素，子数组总是假设是有序的。
 * 此时，将新元素插入到子数组的特定位置，从而形成更大的子数组。
 * 最终，得到完成的排序。
 * 
 * @param a Comparable Array
 * @param size Array length
*/
public void insertionSort(int* a, const int size);


public void shellSort(int* a, const int size);


/**
 * 排序函数测试函数. 
 * 根据输入的排序函数和需要的数组大小，自动进行测试
 * @param fs 特定的排序函数
 * @param size 作为测试对象的数组长度
*/
public void
fSortTest(f_sort fs, const int size);


// private bool safeInsert(int* array, const int array_size, const int ori_position, const int new_position);

#endif
/* f_sort.h */