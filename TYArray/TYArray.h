#ifndef TYARRAY_H_INCLUDED
#define TYARRAY_H_INCLUDED
#include <iostream>

class TYArray
{
    private:
        unsigned int max_size;
        unsigned int curr_size;
    public:
        int * data;
        TYArray(unsigned int& size_): data(new int[size_]), max_size(size_),curr_size(0){};
        ~TYArray();
        void append(const unsigned int&);
        TYArray operator+ (const TYArray&);
        TYArray operator- (const TYArray&);
        int getValue(unsigned int&);
        int operator[] (const unsigned int&);
        int operator() (const unsigned int&);

};

#endif // TYARRAY_H_INCLUDED
