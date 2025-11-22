#include "AForm.hpp"

AForm::AForm(const std::string &Name, const int gradetosign,
	const int gradetoexecute) : name(Name), signature(false),
	gradeToSign(gradetosign), gradeToExecute(gradetoexecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}
std::string AForm::getName() const
{
	return (name);
}

bool AForm::isSigned() const
{
	return (signature);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() <= gradeToSign)
		this->signature = true;
	else
		throw GradeTooLowException();
}
AForm &AForm::operator=(const AForm &oth)
{
	if(this != &oth)
	{
		signature =  oth.signature;
	}
	return *this;
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too High");
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}
AForm::~AForm()
{
}
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form \"" << form.getName() << "\" | Signed: " << (form.isSigned() ? "yes" : "no") << " | Grade to sign: " << form.getGradeToSign() << " | Grade to execute: " << form.getGradeToExecute();
	return (out);
}