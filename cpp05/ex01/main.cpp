#include "Bureaucrat.hpp"




int main()
{
    try {
        Bureaucrat test("nesta", 0); // or 1140
        std::cout << test << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
    }
}
// int age = 15;
// try {
// if (age >= 18) {
//     cout << "Access granted - you are old enough.";
// } else {
//     throw (age);
// }
// }
// catch (int myNum) {
// cout << "Access denied - You must be at least 18 years old.\n";
// cout << "Age is: " << myNum << endl;
// cout << myNum << endl;
// }    