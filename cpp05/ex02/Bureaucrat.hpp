#pragma once
#include <iostream>
#include <string>

class AForm;
class Bureaucrat
{
    private :
    const std::string name;
    int grade;
    public :
    //constructors
    Bureaucrat();
    Bureaucrat(const std::string& Name, int Grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    //methodes
    std::string get_name(void)const;
    int get_grade()const;
    void increment_grade();
    void decrement_grade();
    class GradeTooHighException : public std::exception 
    {
        public :
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception 
    {
        public :
        const char *what() const throw();

    };
    void signForm(AForm &form);
    Bureaucrat& operator=(const Bureaucrat &other);
    void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
