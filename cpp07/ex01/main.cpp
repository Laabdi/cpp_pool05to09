#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& value)
{
    std::cout << value << ' ';
}

void increment(int &n)
{
    ++n;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    const int cnums[] = {10, 20, 30};
    std::string words[] = {"hello", "cpp", "module", "07"};

    std::cout << "Numbers (before): ";
    iter(nums, 5, printElement<int>);
    std::cout << '\n';

    iter(nums, 5, increment);

    std::cout << "Numbers (after): ";
    iter(nums, 5, printElement<int>);
    std::cout << '\n';

    std::cout << "Const numbers: ";
    iter(cnums, 3, printElement<int>);
    std::cout << '\n';

    std::cout << "Words: ";
    iter(words, 4, printElement<std::string>);
    std::cout << '\n';

    return 0;
}