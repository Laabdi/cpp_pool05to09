#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &oth)
{
	if (this != &oth)
	{
		AForm::operator=(oth);
		target = oth.target;
	}
	return (*this);
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	if(!isSigned())
	throw AForm::GradeTooLowException();
	if(executor.get_grade() > getGradeToExecute())
	throw AForm::GradeTooLowException();
	std::ofstream file(target + "_shrubbery");
	file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
}
