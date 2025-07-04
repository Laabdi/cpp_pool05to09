#pragma once
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
	Form::Form(const std::string &Name, const int gradetosign,const int gradetoexecute) : name(Name), signature(false),gradeToSign(gradetosign), gradeToExecute(gradetoexecute)
	{
		// You can add validation or other logic here if needed
	}
	~Form();

	class GradeTooHighException : public std::exception
	{
		const char *what() throw()
		{
			return ("Grade too High");
		}
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() throw()
		{
			return ("Grade too Low");
		}
	};
};