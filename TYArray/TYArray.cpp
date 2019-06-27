#include "TYArray.h"
#include <iostream>
#define INT_MIN -1.005

using namespace std;


TYArray::~TYArray()
{
    delete[] data;
}

void TYArray::append(const unsigned int& value)
{
    if (curr_size < max_size)
    {
        data[curr_size] = value;
        curr_size++;
    }
}

int TYArray::getValue(unsigned int& index)
{
    return data[index];
}

TYArray TYArray::operator+(const TYArray& array2)
{
    TYArray temp(max_size);
    for (unsigned int i = 0; i<max_size; ++i)
        temp.data[i] = data[i] + array2.data[i];
    return temp;

}

TYArray TYArray::operator-(const TYArray& array2)
{
    TYArray temp(curr_size);
    for (unsigned int i = 0; i<curr_size; ++i)
        temp.data[i] = data[i] - array2.data[i];
    return temp;

}

int TYArray::operator[](const unsigned int& index)
{
    if (index>= curr_size)
        return INT_MIN;
    else
        return data[index];
}

int TYArray::operator() (const unsigned int& index)
{
    if (index>= curr_size)
        return INT_MIN;
    else
        return data[index];
}
