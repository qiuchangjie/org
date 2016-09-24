/*
  快速排序
 */

#include <iostream>
#include "SortBase.h"
using namespace std;

class QuickSort : public SortBase
{
private:
    void DoQuickSort(int* array, int left, int right)
    {
        if (left < right)
        {
            int a = array[left];
            int i = left;
            int j = right;
            while (i < j)
            {
                // 此处很重要：基准值在最左边，右边的哨兵j要先移动，如果是i先移动的话，可能会导致i最后找到的大于a的值跟基准值交换，导致结果不正确
                while (array[j] >= a && i < j)
                    --j;
                while (array[i] <= a && i < j)
                    ++i;
                if (i < j)
                {
                    Swap(&array[i], &array[j]);
                }
            }
            if (left != i)
            {
                Swap(&array[left], &array[i]);
            }
            DoQuickSort(array, left, i - 1);
            DoQuickSort(array, i + 1, right);
        }
    }
protected:
    void Sort(int* array, int length)
    {
        DoQuickSort(array, 0, length - 1);
    }
};

int main()
{
    SortBase* sort = new QuickSort();
    sort->Test();
    delete sort;
    return 0;
}
