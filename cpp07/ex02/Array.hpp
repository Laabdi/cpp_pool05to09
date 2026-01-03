#pragma once
#include <stdexcept>
#include <iostream>

template<typename T>
class Array
{
private:
    unsigned int length;
    T *ptr;

public:
    Array() : length(0), ptr(NULL) {}
    Array(unsigned int n) : length(n), ptr(new T[n]()) {}
    Array(const Array &oth) : length(oth.length), ptr(new T[oth.length])
    {
        for (unsigned int i = 0; i < length; ++i)
            ptr[i] = oth.ptr[i];
    }
    Array &operator=(const Array &oth)
    {
        if (this != &oth)
        {
            delete[] ptr;
            length = oth.length;
            ptr = new T[length];
            for (unsigned int i = 0; i < length; ++i)
                ptr[i] = oth.ptr[i];
        }
        return *this;
    }
    T &operator[](unsigned int index)
    {
        if (index >= length)
            throw std::out_of_range("Index out of range");
        return ptr[index];
    }
    const T &operator[](unsigned int index) const
    {
        if (index >= length)
            throw std::out_of_range("Index out of range");
        return ptr[index];
    }
    unsigned int size() const { return length; }
    ~Array() { delete[] ptr; }
};