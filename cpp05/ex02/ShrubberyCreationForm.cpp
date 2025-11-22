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