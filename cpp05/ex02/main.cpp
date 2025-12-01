#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "--- Attempt signing with low-grade intern ---\n";
    intern.signForm(shrub);
    intern.signForm(robo);

    std::cout << "\n--- Boss signs everything ---\n";
    boss.signForm(shrub);
    boss.signForm(robo);
    boss.signForm(pardon);

    std::cout << "\n--- Try execute with wrong grades ---\n";
    intern.executeForm(shrub);
    intern.executeForm(robo);

    std::cout << "\n--- Boss executes forms ---\n";
    boss.executeForm(shrub);
    boss.executeForm(robo);
    boss.executeForm(pardon);

    std::cout << "\n--- Direct calls to execute (also ok) ---\n";
    try 
    {
         shrub.execute(boss); std::cout << "direct executed shrub\n"; 
        } 
    catch (const std::exception &e) 
    {
         std::cerr << e.what() << '\n'; 
    }
    try 
    {
         robo.execute(boss);  std::cout << "direct executed robo\n";  
    } 
    catch (const std::exception &e) 
    {
         std::cerr << e.what() << '\n'; 
        }
    try 
    { pardon.execute(boss);std::cout << "direct executed pardon\n";
    } catch (const std::exception &e) 
    { 
        std::cerr << e.what() << '\n';
    }

    return 0;
}