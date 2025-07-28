#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "Form.hpp"
#include <iostream>
#include <string>

class Bureaucrat
{
    private :
    const std::string name;
    int grade;
    public :
    //constructors
    Bureaucrat();
    Bureaucrat(const std::string& Name, int Grade);
    Bureaucrat(Bureaucrat &other);
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
    void Bureaucrat::SignForm(Form &form);
    Bureaucrat& operator=(Bureaucrat &other);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif