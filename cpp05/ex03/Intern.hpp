#pragma once
#include <iostream>
// #include "AForm.hpp"

class AForm;
class Intern
{
    public :
    Intern();
    Intern(const Intern &oth);
    Intern &operator=(const Intern &oth);
    ~Intern();
    AForm* makeForm(const std::string &form_type,const std::string &targer_form);

};