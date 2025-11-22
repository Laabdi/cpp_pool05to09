#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
  private:
	const std::string name;
	bool signature;
	const int gradeToSign;
	const int gradeToExecute;

  public:
	AForm();
	AForm(const std::string &Name, const int gradetosign,const int gradetoexecute);
	~AForm();
	AForm &operator=(const AForm &oth);
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
	virtual void execute(Bureaucrat const & executor) = 0;
};
std::ostream& operator<<(std::ostream &out, const AForm &form);