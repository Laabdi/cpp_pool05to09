#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    numbers.push_back(0);
    numbers.push_back(1);
    numbers.push_back(2);

    try 
    {
        easyfind(numbers,1);
    }
   catch (const std::exception &e)
    {
        std::cerr << "Caught exception for value :" << e.what() << std::endl;
    }
    return 0;
}