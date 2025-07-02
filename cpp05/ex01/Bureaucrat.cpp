
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150){}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade) : name(Name)
{

		if (Grade > 150)
		{
			throw GradeTooHighException();
		}
		if (Grade < 1)
		{
			throw GradeTooLowException();
		}
		
	this->grade = Grade;
}
Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name) , grade(other.grade){}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.get_name() << ", bureaucrat grade " << b.get_grade();
	return (os);
}

std::string Bureaucrat::get_name(void) const
{
	return (this->name);
}
int Bureaucrat::get_grade() const
{
	return (this->grade);
}
void Bureaucrat::increment_grade()
{
	if(grade <= 1)
	throw GradeTooHighException();
	grade--;
}
void Bureaucrat::decrement_grade()
{
	if(grade >= 150)
	throw GradeTooLowException();
	grade++;
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
return("GRADE TO LOW\n");
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GRADE TO HIGH\n";
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
    if(this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
    }