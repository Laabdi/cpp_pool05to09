#pragma once
#include <iostream>

class RobotomyRequestForm
{
    private:
    std::string target;
    public :
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string targ);
    RobotomyRequestForm(const RobotomyRequestForm &oth);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &oth);
    ~RobotomyRequestForm();

};