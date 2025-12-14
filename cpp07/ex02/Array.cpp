#include "Array.hpp"

template<typename T>
Array<T>::Array() : ptr(nullptr) , length(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : ptr(new(T[length])) , lenght(n) {}

template<typename T>
Array<T>::Array(const Array &oth) : ptr(oth.ptr) , lenght(oth.ptr) {}

template<typename T>
Array<T>& Array<T>::operator=(const Array &oth)
{
    if(this != &oth)
    {
        ptr = oth.ptr;
        length = oth.length;
    }
    return  *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    T *a =  new T[];
    return (new(T[index]))
}


template<typename T>
unsigned int Array<T>::size(){ return lenght;}