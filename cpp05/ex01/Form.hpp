#pragma once
#include "Bureaucrat.hpp"
#include <iostream>>

class Form
{
  private:
	const std::string name;
	bool signature;
	const int gradeToSign;
	const int gradeToExecute;

  public:
	Form();
	Form(const std::string &Name, const int gradetosign,
		const int gradetoexecute);
	~Form();
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void Besigned(Bureaucrat &bureaucrat);
	void SignForm(Form &form);
	class GradeTooHighException : public std::exception
	{
		const char *what() throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() throw();
	};
};