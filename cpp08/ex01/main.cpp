#include "Span.hpp"


int main()
{
    Span test(3);
    try
    {
        test.addNumber(10);
        test.addNumber(2);
        test.addNumber(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::vector<int> ar =  test.get_array();
    for(int i = 0 ;i < 3;i++)
    std::cout << "index [" << i << "] : " << ar[i] << std::endl;
    std::cout << "shortest span :" << test.shortestSpan() << std::endl;
    std::cout << "longest span :" << test.longestSpan() << std::endl;

}