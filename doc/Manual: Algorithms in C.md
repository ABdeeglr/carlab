# Algorithms in C

- sort
- search
- graph
- string

## Sort

### 简介

有关排序（sort）的算法被统一存放于 `f_sort` 包内。

#### 头文件 `f_sort.h`

`f_sort.h` 中提供了排序算法本身的原型(primitive)，其实现被存放在 `f_sort.c` 文件中。

`f_sort.h` 中提供的函数包括：

```c
void selectSort(int* a, const int size); // 选择排序
void insertionSort(int* a, const int size); // 插入排序
void shellSort(int* a, const int size); // 希尔排序
```


#### 头文件 `libfss.h`

`f_sort.c` 实现涉及到一些辅助函数、测试函数，这些提供额外支持的函数的原型被存放于 `libfss.h` 头文件中。`libfss.h` 包含三个部分：宏(macro), 辅助函数和测试函数。

**1 宏和类型定义**：

对于数组而言，经常出现的操作是接受一个数组和数组大小作为参数，进行某些操作，并不返回任何值。比如本包内的排序函数，均为堆排序函数，数组被排序后，数组本身的地址不会改变，而其中的元素顺序发生了变化。

因此，`ArraySorter` 和 `ArrayProducter` 抽象了这些函数的共同特征。在进行性能测试或其它操作时，传递函数指针而不是调用会更方便。

```c
typedef void (*ArraySorter)(int*, const int);
typedef ArraySorter ArrayProducter;
```
在上面的类型定义中，本质上相同的两个类型在语义上做出了区分，这让源代码更容易重构和理解。


**2 辅助函数**

无论是测试、还是构建实际的排序函数，一些辅助函数是十分有用的。它们可以分为副作用需求和返回值需求两个部分。

需求副作用，意味着仅仅对数组进行一些操作，比如

```c
void reverseArray(int* __array, const int __size);
void printArray(int* __array, const int __size);
void exchange(int* ary, const int index_a, const int index_b);
bool safeInsert(int* array, const int array_size, const int ori_position, const int new_position);
```
它们实现了翻转数组、打印数组、交换数组中的两个元素的功能。

需求返回值的：

```c
int ascendingSearch(int* asceding_array, const int size, const int value);
int binarySearch(int* ascending_array, const int __size, const int __value);
int* intArrayGenerator(const int size, const int boundary);
```

它们的功能分别为：
1. 输入一个有序数组和一个新的值，返回一个位置，使得新值在该位置插入数组后，新数组仍然保持有序。
2. 二分查找。输入一个有序数组和查找的值，如果该值在数组中，则返回第一次匹配的位置，否则返回 -1
3. 数组生成。在堆上分配一个指定大小的数组，防止爆栈。



最后，还有一些测试用的函数。

```c
long arrayProducterTiming(ArrayProducter ap, int* __array, const int __size);
void fSortTest(ArraySorter fs, const int __size);
bool fSortCertifyTest(ArraySorter fs, const int __size);
bool ascendOrderTest(int* __array, const int __size);
```

它们实现了以下功能：
1. `arrayProducterTiming` 提供对数组操作占用的 CPU 时间进行统计。函数执行时打印使用的时间，并返回使用的时间。这个函数足够简单，因此可以被更多其他测试函数复用。
2. `fSortTest` 接受一个排序算法函数变量和数组规模变量，检查该排序算法在当前规模的运行时间，并判断排序算法的正确性。这个函数适合 Debug.
3. `fSortCertifyTest` 接受一个排序函数，判断该排序函数是否能正确排序。它是其他测试的一部分。
4. `ascendOrderTest` 判断一个数组是否以升序排列。