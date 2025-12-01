#include "Form.hpp"

Form::Form() : name("default"), signature(false), grade_to_sign(150), grade_to_execute(150) {}


Form::Form(const std::string &Name, const int gradetosign,
	const int gradetoexecute) : name(Name), signature(false),
	gradeToSign(gradetosign), gradeToExecute(gradetoexecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}
Form &Form::operator=(const Form &oth)
{
	if(this != &oth)
	{
		signature =  oth.signature;
	}
	return *this;
}

std::string Form::getName() const
{
	return (name);
}

bool Form::isSigned() const
{
	return (signature);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() <= gradeToSign)
		this->signature = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too High");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}
Form::~Form()
{
}
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form \"" << form.getName() << "\" | Signed: " << (form.isSigned() ? "yes" : "no") << " | Grade to sign: " << form.getGradeToSign() << " | Grade to execute: " << form.getGradeToExecute();
	return (out);
}