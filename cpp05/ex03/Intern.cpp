#include "Intern.hpp"
#include <vector>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{

}
Intern::Intern(const Intern &oth)
{
    (void)oth;
}
Intern &Intern::operator=(const Intern &oth)
{
    (void)oth;
    return *this;
}
Intern::~Intern()
{

}

AForm* Intern::createShrubbery(const std::string& target) 
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &form_type,const std::string &target_form)
{
    std::string forms[3] = 
    {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };
    
    AForm* (Intern::*ptr[3])(const std::string &str) = {&createRobotomy,&createShrubbery,&createPardon};
    for(int i = 0;i < 3;i++)
    {
        if(forms[i] == form_type)
        {
            std::cout << "Intern creates " << form_type << std::endl;
          return (this->*ptr[i])(target_form); 
        }
    }
    std::cerr << "Error : Unkown Type " << std::endl;
    return NULL;
}
