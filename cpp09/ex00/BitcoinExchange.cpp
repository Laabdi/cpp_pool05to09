#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <sstream>
#include "BitcoinExchange.hpp"


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
bool is_valid_date(const std::string &date)
{
    if (date.size() != 10)
        return false;
    
    for (size_t i = 0; i < date.size(); i++)
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
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (year < 1000 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}

std::map<std::string, float> fill_database(const char *filename)
{
    std::map<std::string, float> database;
    std::ifstream file(filename);
    
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return database;
    }
    
    std::string line;
    bool first_line = true;
    
    while (std::getline(file, line))
    {
        if (first_line)
        {
            first_line = false;
            continue;
        }
        
        std::vector<std::string> divided_line = ft_split_request(line, ",");
        if (divided_line.size() == 2)
        {
            try
            {
                std::string key = divided_line[0];
                float value = std::stof(divided_line[1]);
                database[key] = value;
            }
            catch (const std::exception &e)
            {
                continue;
            }
        }
    }
    
    file.close();
    return database;
}

void process_line(const std::string &line, const std::map<std::string, float> &database)
{
    if (line == "date | value")
        return;
    
    std::vector<std::string> parts = ft_split_request(line, "|");
    
    if (parts.size() != 2)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    
    std::string date = trim(parts[0]);
    std::string value_str = trim(parts[1]);

    if (!is_valid_date(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    float value;
    try
    {
        value = std::stof(value_str);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: invalid value." << std::endl;
        return;
    }
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    auto it = database.lower_bound(date);
    if (it == database.end() || (it->first != date && it != database.begin()))
    {
        if (it == database.end() || it->first != date)
        {
            if (it != database.begin())
                --it;
            else if (it == database.end())
            {
                std::cerr << "Error: no exchange rate available for date." << std::endl;
                return;
            }
        }
    }

    if (it == database.end())
    {
        std::cerr << "Error: no exchange rate available for date." << std::endl;
        return;
    }
    float result = value * it->second;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

// Process input file
void process_input(const char *filename, const std::map<std::string, float> &database)
{
    std::ifstream file(filename);  
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        process_line(line, database);
    }
    file.close();
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::map<std::string, float> database = fill_database("data.csv");
    
    if (database.empty())
    {
        std::cerr << "Error: database is empty." << std::endl;
        return 1;
    }
    process_input(av[1], database);
    
    return 0;
}