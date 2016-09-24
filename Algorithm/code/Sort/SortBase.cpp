/*
  Author: ChangJie.Qiu
  Email: qiuchangjie@foxmail.com
  排序基类
 */
#include "SortBase.h"

void SortBase::Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SortBase::InputArray(int* array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cin >> array[i];
    }
}

void SortBase::OutputArray(int* array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void SortBase::Test()
{
    cout << "input n: ";
    cin >> _count;
    int* array = new int[_count];
    cout << "input array: ";
    InputArray(array, _count);
    cout << "output array befor sort: " << endl;
    OutputArray(array, _count);
    Sort(array, _count);
    cout << "output array after sort: " << endl;
    OutputArray(array, _count);
    delete[] array;
}
