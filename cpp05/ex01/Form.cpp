#include "Form.hpp"

Form::Form(const std::string &Name, const int gradetosign,
	const int gradetoexecute) : name(Name), signature(false),
	gradeToSign(gradetosign), gradeToExecute(gradetoexecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}
std::string Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signature;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}
void Form::Besigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() <= gradeToSign)
		this->signature = true;
	else
		throw GradeTooLowException();
}


const char *Form::GradeTooHighException::what() throw()
{
	return ("Grade too High");
}
const char *Form::GradeTooLowException::what() throw()
{
	return ("Grade too Low");
}