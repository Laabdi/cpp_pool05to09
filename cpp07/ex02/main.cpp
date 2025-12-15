#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    Array<int> a(3);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i + 1);

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';

    Array<int> b = a;
    b[1] = 99;
    std::cout << "after copy, a[1] = " << a[1] << ", b[1] = " << b[1] << '\n';

    Array<std::string> s(2);
    s[0] = "hello";
    s[1] = "world";
    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << s[i] << ' ';
    std::cout << std::endl;

    try {
        std::cout << a[10] << '\n';
    } catch (const std::exception &e) {
        std::cout << "caught: " << e.what() << '\n';
    }

    return 0;
}