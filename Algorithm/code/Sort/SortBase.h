#include <iostream>
using namespace std;

class SortBase
{
protected:
    int _count;

    void Swap(int* a, int* b);
    virtual void InputArray(int* array, int length);
    virtual void OutputArray(int* array, int length);
    virtual void Sort(int* array, int length) = 0;
public:
    void Test();
};
