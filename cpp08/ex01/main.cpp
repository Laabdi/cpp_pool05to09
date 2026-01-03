#include "Span.hpp"


int main()
{
    Span test(3);
    try
    {
        test.addNumber(1);
        test.addNumber(2);
        test.addNumber(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for(int i = 0 ;i < 3;i++)
    std::cout << "index " << i << test.array[i] << std::endl;

}