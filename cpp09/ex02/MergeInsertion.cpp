#include "MergeInsertion.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

std::vector<std::pair<int, int>> string_to_pairs(std::vector<std::string> &str_array, int &last_int)
{
    int	a1;
    int	a2;
    int	i;
    int	j;

    std::vector<int> array;
    std::vector<std::pair<int, int>> test;
    
    for(int i = 0; i < str_array.size(); i++)
    {
        std::istringstream iss(str_array[i]);
        int num;
        if (!(iss >> num))
        {
            std::cout << "Error: invalid input" << std::endl;
            exit(1);
        }
        array.push_back(num);
    }
    
    if (array.size() < 2)
    {
        std::cout << "not enough parametres" << std::endl;
        exit(1);
    }
    
    if (array.size() % 2 != 0)
    {
        last_int = array.back();
        array.pop_back();
    }
    
    i = 0;
    j = 1;
    while (i < array.size() && j < array.size())
    {
        a1 = array[i];
        a2 = array[j];
        if (a1 < a2)
            test.push_back(std::pair<int, int>(a1, a2));
        else
            test.push_back(std::pair<int, int>(a2, a1));
        i += 2;
        j += 2;
    }
	std::sort(test.begin(),test.end());
    	return (test);
}

void	print_vector(const std::vector<int> &alo)
{
	for(int i = 0;i < alo.size();i++)
	{
		std::cout << alo[i] << " ,";
	}
}
std::pair<std::vector<int>,std::vector<int>>
	 create_w_a_l(std::vector<std::pair<int, int>> &alo)
{
	std::vector<int> winner;
	std::vector<int> loser;
	for (int i = 0; i < alo.size(); i++)
	{
		loser.push_back(alo[i].second);
		winner.push_back(alo[i].first);
	}
	std::cout << "winners" << std::endl;
	print_vector(winner);
	std::cout << "\n";
	std::cout << "losers" << std::endl;
	print_vector(loser);
    return std::make_pair(winner,loser);
}
std::vector<int> generate_jacobsthal(int n)
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
std::vector<std::string> av_to_strings(char **av,int ac)
{
	std::vector<std::string> array;
	for(int i = 1;i < ac;i++)
	{
		array.push_back(std::string(av[i]));
	}
	return array;
}
bool compare_by_second(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.second < b.second;
}
int main(int ac,char **av)
{
	if(ac < 2)
		return(printf("error invalid n parametres\n"),1);
	std::vector<std::string> array = av_to_strings(av,ac);
    int last = 0;
    std::vector<std::pair<int,int>> alo = string_to_pairs(array,last);
    for(int i = 0;i < alo.size();i++)
    {
        std::cout << "pair " << i << std::endl;
        std::cout << alo[i].first << std::endl;
        std::cout << alo[i].second << "\n";
    }
	// std::pair<std::vector<int>, std::vector<int>> to_return = create_w_a_l(alo);
	// std::pair<std::vector<int>, std::vector<int>> sorted_one = sort_pairs(to_return);

}