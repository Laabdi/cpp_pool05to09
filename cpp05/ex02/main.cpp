#include "Bureaucrat.hpp"

using namespace	std;

int	main(void)
{
	try
	{
		Bureaucrat b("Alice", 42);
		Form f("Tax Form", 50, 100);
		std::cout << "Form name: " << f.getName() << std::endl;
		std::cout << "Form signed: " << (f.isSigned() ? "yes" : "no") << std::endl;
		std::cout << "Form grade to sign: " << f.getGradeToSign() << std::endl;
		std::cout << "Form grade to execute: " << f.getGradeToExecute() << std::endl;
		// Try to sign the form
		try
		{
			f.beSigned(b);
			std::cout << "Form signed by " << b.get_name() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << b.get_name() << " couldn't sign form because: " << e.what() << std::endl;
		}
		std::cout << "Form signed: " << (f.isSigned() ? "yes" : "no") << std::endl;
		// Bureaucrat's SignForm method
		b.signForm(f);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
//     try {
//         Bureaucrat b("Alice", 42);
//         Form f("Tax Form", 50, 100);
//         std::cout << f << std::endl;
//         b.SignForm(f);
//         std::cout << f << std::endl;
//     }
//     catch (const std::exception& e) {
//         std::cerr << e.what();
//     }