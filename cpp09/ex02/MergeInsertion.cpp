#include "MergeInsertion.hpp"
#include <iostream>
#include <sstream>
#include <string>

std::vector<std::pair<int, int>> string_to_vector(std::string &str,
	int &last_int)
{
	int	num;
	int	a1;
	int	a2;
	int	i;
	int	j;

	std::vector<std::pair<int, int>> test;
	std::istringstream splited(str);
	std::vector<int> array;
	while (splited >> num)
		array.push_back(num);
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
	//     for(int i = 0;i < array.size();i++)
	// {
	//     std::cout << array[i] << std::endl;
	// }
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
	std::cout << last_int << std::endl;
	return (test);
}

void	print_vector(const std::vector<int> &alo)
{
}
std::pair<std::vector<int>,
	std::vector<int>> create_w_a_l(std::vector<std::pair<int, int>> &alo)
{
	std::vector<int> winner;
	std::vector<int> loser;
	for (int i = 0; i < alo.size(); i++)
	{
		loser.push_back(alo[i].second);
		winner.push_back(alo[i].first);
	}
}

// int main()
// {
//     std::string t = "9 6 8 4 7";
//     int last = 0;
//     std::vector<std::pair<int,int>> alo = string_to_vector(t,last);
//     for(int i = 0;i < alo.size();i++)
//     {
//         std::cout << "pair " << i << std::endl;
//         std::cout << alo[i].first << std::endl;
//         std::cout << alo[i].second << "\n";
//     }
//     std::cout<< "last element :"<< last << std::endl;

// }