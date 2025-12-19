#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("",145,137) , target("") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targ) : AForm("ShrubberyCreationForm",145,137) , target(targ) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oth) : AForm(oth) ,target(oth.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &oth)
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
	std::ofstream file((target + "_shrubbery").c_str());
	file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
