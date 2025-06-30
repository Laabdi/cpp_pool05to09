
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
	this->name == "";
	this->grade = 0;
}

 Bureaucrat::Bureaucrat(const std::string& Name, int Grade)
{
	this->name == Name;
	try
	{
		if(Grade >= 1 && Grade <= 150)
		{
			this->grade = Grade;
		}

		throw grade;
	}
	catch(int myerror)
	{
		if(Grade > 150)
		{
			std::cout << "Bureaucrat::GradeTooHighException " << std::endl;
		}
		else if (Grade < 1)
		{
			std::cout << "a Bureaucrat::GradeTooLowException " << std::endl;

		}
	}

}

std::ostream& operator<<(std::ostream& os,const Bureaucrat& b)
	{
		os << b.get_name() << ", bureaucrat grade " << b.get_grade();
		return os;
	}

	std::string Bureaucrat::get_name(void)const
	{
		return this->name;
	}
	int  Bureaucrat::get_grade()const
	{
		return this->grade;
	}
	void Bureaucrat::increment_grade()
	{
		grade--;
	}
		void  Bureaucrat::decrement_grade()
	{
		grade++;
	}