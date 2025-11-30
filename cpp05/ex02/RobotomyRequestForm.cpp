#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",72,45)  , target(""){}
RobotomyRequestForm::RobotomyRequestForm(const std::string targ) : AForm("RobotomyRequestForm",72,45) , target(targ) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oth) : AForm(oth) , target(oth.target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &oth)
{
    if (this != &oth) {
        AForm::operator=(oth);
        target = oth.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
void  execute(Bureaucrat const & executor)
{

}