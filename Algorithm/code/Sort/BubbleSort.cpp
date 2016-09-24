/*
   冒泡排序
 */

#include <iostream>
using namespace std;
#include "SortBase.h"

class BubbleSort : public SortBase
{
protected:
    void Sort(int* array, int length)
    {
        for (int i = 0; i < length; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                if (array[j] > array[j + 1])
                {
                    Swap(&array[j], &array[j + 1]);
                }
            }

        }
    }
};

int main()
{
    SortBase* sort = new BubbleSort();
    sort->Test();
    delete sort;
    return 0;
}
