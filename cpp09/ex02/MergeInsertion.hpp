#ifndef MERGEINSERTION_HPP
#define MERGEINSERTION_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>

inline std::vector<int> generate_jacobsthal(int n)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    if (n >= 1)
        jacobsthal.push_back(1);
    
    for (int i = 2; i <= n; i++)
    {
        int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

template <typename Container>
Container parse_input(int ac, char **av, int &last_int)
{
    Container numbers;
    
    for(int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        int num;
        if (!(iss >> num) || num < 0)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        numbers.push_back(num);
    }
    
    if (numbers.size() % 2 != 0)
    {
        last_int = numbers.back();
        numbers.pop_back();
    }
    else
    {
        last_int = -1;
    }
    
    return numbers;
}

template <typename Container>
std::vector<std::pair<int, int> > create_pairs(Container &numbers)
{
    std::vector<std::pair<int, int> > pairs;
    
    typename Container::iterator it = numbers.begin();
    while (it != numbers.end())
    {
        int first = *it;
        ++it;
        if (it != numbers.end())
        {
            int second = *it;
            ++it;
            
            if (first > second)
                pairs.push_back(std::make_pair(first, second));
            else
                pairs.push_back(std::make_pair(second, first));
        }
    }
    
    std::sort(pairs.begin(), pairs.end());
    return pairs;
}

template <typename Container>
Container ford_johnson_sort(Container &numbers, int last)
{
    if (numbers.size() == 0)
    {
        Container result;
        if (last != -1)
            result.push_back(last);
        return result;
    }
    if (numbers.size() == 1)
    {
        Container result;
        result.push_back(numbers.front());
        if (last != -1)
        {
            if (last < numbers.front())
                result.insert(result.begin(), last);
            else
                result.push_back(last);
        }
        return result;
    }  
    std::vector<std::pair<int, int> > pairs = create_pairs(numbers);  
    Container main_chain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        main_chain.push_back(pairs[i].first);
    }
    
    if (pairs.size() > 0)
    {
        main_chain.insert(main_chain.begin(), pairs[0].second);
    }
    std::vector<int> jacob = generate_jacobsthal(pairs.size());
    std::vector<int> insertion_order;
    int prev_jacob = 1;
    for (size_t i = 2; i < jacob.size() && static_cast<size_t>(jacob[i]) < pairs.size(); i++)
    {
        int curr_jacob = jacob[i];
        for (int j = curr_jacob; j > prev_jacob; j--)
        {
            if (static_cast<size_t>(j) < pairs.size())
                insertion_order.push_back(j);
        }
        prev_jacob = curr_jacob;
    } 
    for (size_t j = prev_jacob + 1; j < pairs.size(); j++)
    {
        insertion_order.push_back(j);
    }   
    for (size_t i = 0; i < insertion_order.size(); i++)
    {
        int idx = insertion_order[i];
        int value = pairs[idx].second; 
        typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }
    if (last != -1)
    {
        typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), last);
        main_chain.insert(pos, last);
    }
    return main_chain;
}

inline long long get_time_us()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

#endif