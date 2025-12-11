#pragma once

template <typename T>
void iter(T *p,const int size,void (*function)(T&))
{
    if (!p || size <= 0)
        return;
    for(int i = 0;i < size;i++)
    {
        function(p[i]);
    }
}
template<typename T>
void increment(T &b)
{
    b++;
}