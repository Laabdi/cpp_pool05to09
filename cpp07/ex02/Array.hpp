#pragma once

template<typename T>
class Array
{
    private :
    unsigned int lenght;
    T *ptr;
    public :
    Array();
    Array(unsigned int n);
    Array(const Array &oth);
    Array &operator=(const Array &oth);
    T &operator[](unsigned int index);
    unsigned int size();
};