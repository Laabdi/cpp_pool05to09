#pragma once
#include <iostream>
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
    private :
    std::string target;
    public :
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &targ);
    PresidentialPardonForm(const PresidentialPardonForm &oth);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &oth);
    ~PresidentialPardonForm();
    void  execute(Bureaucrat const & executor)const;
};