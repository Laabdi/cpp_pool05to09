#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;
    public :
    ShrubberyCreationForm() : AForm("",0,0) , target("") {}
    ShrubberyCreationForm(std::string targ) : AForm("ShrubberyCreationForm",145,137) , target(targ) {}
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &oth);

};