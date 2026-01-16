#include "MergeInsertion.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: invalid number of parameters" << std::endl;
        return 1;
    }
    
    std::cout << "Before: ";
    for (int i = 1; i < ac; i++)
    {
        std::cout << av[i];
        if (i < ac - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    int last_vec = -1;
    std::vector<int> vec_numbers = parse_input<std::vector<int> >(ac, av, last_vec);
    long long start_vec = get_time_us();
    std::vector<int> sorted_vec = ford_johnson_sort(vec_numbers, last_vec);
    long long end_vec = get_time_us();  
    int last_deq = -1;
    std::deque<int> deq_numbers = parse_input<std::deque<int> >(ac, av, last_deq);  
    long long start_deq = get_time_us();
    std::deque<int> sorted_deq = ford_johnson_sort(deq_numbers, last_deq);
    long long end_deq = get_time_us();
    std::cout << "After: ";
    for (size_t i = 0; i < sorted_vec.size(); i++)
    {
        std::cout << sorted_vec[i];
        if (i < sorted_vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << (ac - 1) << " elements with std::vector : " 
              << (end_vec - start_vec) << " us" << std::endl;
    std::cout << "Time to process a range of " << (ac - 1) << " elements with std::deque : " 
              << (end_deq - start_deq) << " us" << std::endl;
    
    return 0;
}