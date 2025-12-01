#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;
    public :
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &targ);
    ShrubberyCreationForm(const ShrubberyCreationForm &oth);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &oth);
    void  execute(Bureaucrat const & executor)const;
    ~ShrubberyCreationForm();
};