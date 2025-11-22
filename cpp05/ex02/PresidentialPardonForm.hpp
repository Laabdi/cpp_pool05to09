#pragma once
#include <iostream>

class PresidentialPardonForm
{
    private :
    std::string target;
    public :
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &targ);
    PresidentialPardonForm(const PresidentialPardonForm &oth);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &oth);
    ~PresidentialPardonForm();

};