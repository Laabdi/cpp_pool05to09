#include "BitcoinExchange.hpp"

int count_occurance(std::string &string)
{
    int count = 0;
    for(int  i = 0;i < string.size();i++)
    {
        if(string[i] == '-')
            count++;
    }
    return count;
}
std::vector<std::string> ft_split_request(const std::string &request,const std::string &delimiter)
{
	size_t	start;
	size_t	pos;

	std::vector<std::string> parts;
	if (delimiter.empty())
	{
		parts.push_back(request);
		return (parts);
	}
	start = 0;
	while ((pos = request.find(delimiter, start)) != std::string::npos)
	{
		parts.push_back(request.substr(start, pos - start));
		start = pos + delimiter.length();
	}
	parts.push_back(request.substr(start));
	return (parts);
}
bool str_all_digist(std::string &date)
{
    for(int i = 0;i < date.size();i++)
    {
        if(!isalnum(date[i]))
        return false;
    }
    return true;
}
bool all_str_digits(std::vector<std::string> &date)
{
    for(int i = 0; i < date.size();i++)
    {
        if(!str_all_digist(date[i]))
            return false;
    }
    return true;
}
// bool parse_date(std::string &date)
// {
//     if(count_occurance(date) != 2)
//         return false;
//     std::vector<std::string> splited = ft_split_request(date,"-");
    
    
// }