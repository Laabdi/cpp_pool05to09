#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool signature;
	const int gradeToSign;
	const int gradeToExecute;

  public:
	Form();
	Form(const std::string &Name, const int gradetosign,const int gradetoexecute);
	Form &operator=(const Form &oth);
	~Form();
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream &out, const Form &form);