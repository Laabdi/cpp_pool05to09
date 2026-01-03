#pragma once

template <typename T,typename S>
void iter(T *p,const int size,S function)
{
    for(int i = 0;i < size;i++)
    {
        function(p[i]);
    }
}