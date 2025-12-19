#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",72,45)  , target(""){}
RobotomyRequestForm::RobotomyRequestForm(const std::string &targ) : AForm("RobotomyRequestForm",72,45) , target(targ) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oth) : AForm(oth) , target(oth.target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &oth)
{
    if (this != &oth) {
        AForm::operator=(oth);
        target = oth.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned()) 
    throw AForm::GradeTooLowException();
    if (executor.get_grade() > getGradeToExecute())
    throw AForm::GradeTooLowException();
    static int counter = 0;
    ++counter;
    std::cout << "Bzzzz... drilling noises..." << std::endl;
    if (counter % 2 == 0)
    std::cout << target << " has been robotomized successfully" << std::endl;
    else
    std::cout << "The robotomy of " << target << " failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}