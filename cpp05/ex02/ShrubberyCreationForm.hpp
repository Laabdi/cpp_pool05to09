#pragma once
#include "AForm.hpp"

#include <fstream>
class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;
    public :
    ShrubberyCreationForm() : AForm("",145,137) , target("") {}
    ShrubberyCreationForm(std::string targ) : AForm("ShrubberyCreationForm",145,137) , target(targ) {}
    ShrubberyCreationForm(const ShrubberyCreationForm &oth) : AForm(oth) ,target(oth.target) {}
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &oth);
    void  execute(Bureaucrat const & executor)const;

};