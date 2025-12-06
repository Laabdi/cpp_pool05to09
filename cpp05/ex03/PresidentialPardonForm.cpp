#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &targ)  : AForm("PresidentialPardonForm", 25, 5), target(targ) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &oth): AForm(oth), target(oth.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &oth)
{
    if (this != &oth) {
        AForm::operator=(oth);
        target = oth.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw AForm::GradeTooLowException();
    if (executor.get_grade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
