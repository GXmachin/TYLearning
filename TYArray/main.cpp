#include <iostream>
#include "TYArray.h"

using namespace std;

int main()
{
    unsigned int size_ = 4;
    TYArray arr(size_);
    TYArray arr2(size_);
    arr.append(4);
    arr.append(3);
    arr.append(2);
    arr.append(6);
    arr2.append(4);
    arr2.append(3);
    arr2.append(2);
    arr2.append(6);
    TYArray sum = arr + arr2;
    for (unsigned int i = 0; i<size_; i++)
        cout << sum.data[i] << endl;
}
