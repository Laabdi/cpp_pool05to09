#pragma once
#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
    private:
    std::string target;
    public :
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string targ);
    RobotomyRequestForm(const RobotomyRequestForm &oth);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &oth);
    ~RobotomyRequestForm();
    void  execute(Bureaucrat const & executor)const;

};