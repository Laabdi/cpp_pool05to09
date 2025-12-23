#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "BitcoinExchange.hpp"
// Helper function to trim whitespace
std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::vector<std::string> ft_split_request(const std::string &request, const std::string &delimiter)
{
    size_t start;
    size_t pos;

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

bool parse_date(std::string &date,Info &filler)
{
    if (date.size() != 10)
        return false;
    for (int i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (!isdigit(date[i]))
                return false;
        }
    }
    int year = std::stoi(date.substr(0, 4));
    // std::cout << year << std::endl;
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (year < 1000 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    filler.set_day(day);
    filler.set_month(month);
    filler.set_year(year);
    return true;
}

bool all_digits(std::string &num)
{
    for (int i = 0; i < num.size(); i++)
    {
        if (!isdigit(num[i]))
            return false;
    }
    return true;
}

void parse_line(std::string &line,Info &filler)
{
    std::vector<std::string> list;
    list = ft_split_request(line, "|");
    if(list.size() == 2)
    {
        std::string trimmed = trim(list[1]);
        std::cout << trimmed << std::endl;
        std::string trimmedd = trim(list[0]);
        std::cout << trimmedd<< std::endl;
    
        if (!all_digits(trimmed) || !parse_date(trimmedd,filler))
            std::cout << "error \n" << std::endl;
        else
        {
            filler.set_value(std::stoi(trimmed.substr(0,1)));
            std::cout << "success \n" << std::endl;
        }
    }
    else
    {
        std::string trimm = trim(line);
        if (!parse_date(trimm,filler))
            std::cout << "error \n" << std::endl;
        else
            std::cout << "success \n" << std::endl;
    }
}

int main()
{
    std::string date = "2001-12-12 | 3";
    Info test;
    parse_line(date,test);
    std::cout << test.get_day() << std::endl;
    std::cout << test.get_year() << std::endl;
    std::cout << test.get_month() << std::endl;
    std::cout << test.get_value() << std::endl;
}