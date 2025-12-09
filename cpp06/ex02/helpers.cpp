#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    
    int random = rand() % 3;
    
    if (random == 0)
    {
        std::cout << "A" << std::endl;
        return new A(); 
    }
    else if (random == 1)
    {
        std::cout << "B" << std::endl;
        return new B(); 
    }
    else
    {
        std::cout << "C" << std::endl;
        return new C();
    }
}
void identify(Base* p)
{

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}
void identify(Base& p)
{

}
int main()
{
    Base *p = generate();
    identify(p);
}