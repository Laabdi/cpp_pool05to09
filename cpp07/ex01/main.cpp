#include "iter.hpp"
#include <iostream>

int main()
{
    char c[3] = "tt";
    iter(c,3,increment);
    std::cout << c[0] << std::endl;
    std::cout << c[1] << std::endl;
    std::cout << c[2] << std::endl;

}