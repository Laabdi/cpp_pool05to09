#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private :
    const std::string name;
    int grade;
    public :
    Bureaucrat();
    Bureaucrat(const std::string& Name, int Grade);
    std::string get_name(void)const;
    int get_grade()const;
    void increment_grade();
    void decrement_grade();
    Bureaucrat(Bureaucrat &other)
    {
        if(this != &other)
        {
            other.name = name;
            other.grade = grade;
        }
    }
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif