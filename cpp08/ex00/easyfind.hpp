#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
void easyfind(T &p,int n)
{
    typename T::iterator it =  std::find(p.begin(),p.end(),n);
    if(it == p.end())
    {
        throw std::runtime_error ("Not Found \n");
    }
    std::cout << "value found" << std::endl;
    return;
};