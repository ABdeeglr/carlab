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
typedef int (*compare)(void* a, void* b);

friend int* createIntArray();

friend int natural_compare(int a, int b);

friend void exchange(int* ary, const int index_a, const int index_b);

friend void printArray(int* array, const int size);


/**
 * <p>
 * 首先，找到数组中最小的那个元素，<br>
 * 其次，将它和数组的第一个元素交换位置（如果第一个元素就是最小元素那么它就和自己交换）。<br>
 * 再次，在剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置。<br>
 * 如此往复，直到将整个数组排序。<br>
 * 这种方法叫做选择排序，因为它在不断地选择剩余元素之中的最小者。<br><p/>
 * @param a Comparable Array
 */
public void selectSort(int* a, const int size);
public void insertSort(int* a, const int size);
public void shellSort(int* a, const int size);




#endif
/* f_sort.h */