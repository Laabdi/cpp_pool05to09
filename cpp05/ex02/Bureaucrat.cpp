
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150){}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade) : name(Name)
{

		if (Grade > 150)
		{
			throw GradeTooLowException();
		}
		if (Grade < 1)
		{
			throw GradeTooHighException();
		}
		
	this->grade = Grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) , grade(other.grade){}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.get_name() << ", bureaucrat grade " << b.get_grade();
	return (os);
}


void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << get_name() << " signed " << form.getName() << std::endl;
		
	}
	catch(const std::exception &e)
	{

		std::cout << get_name() << " couldn't sign " << form.getName()<< " because " << e.what() << std::endl;
	}
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
return("Grade too low\n");
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high\n";
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}
void Bureaucrat::executeForm(AForm const & form) const
{
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}