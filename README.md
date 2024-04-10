# README

## Versions

### v1.0

一句话总结：选择排序和插入排序的时间复杂度都在 O(n^2) 左右. 当数据规模超过 10^4 后几乎慢得要死.

由于插入排序引入了二分查找进行了一丢丢优化，总体上它比选择排序快一倍.

**插入排序的状况**:

```sh
进行正确性测试...
正确性测试通过!
In scale of 10^2, average time cost is 13.
In scale of 10^3, average time cost is 839.
In scale of 10^4, average time cost is 48910.
In scale of 10^5, average time cost is 4752390.
```

**选择排序的状况**:

```sh
进行正确性测试...
正确性测试通过!
进行性能分析...
In scale of 10^2, average time cost is 14.
In scale of 10^3, average time cost is 1127.
In scale of 10^4, average time cost is 106972.
In scale of 10^5, average time cost is 11311960.
```
