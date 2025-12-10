#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
    static bool s = false;
    if (!s) 
    {
        srand(time(NULL));
        s = true;
    }
    
    int random = rand() % 3;
    
    if (random == 0)
    {
        return new A(); 
    }
    else if (random == 1)
    {
        return new B(); 
    }
    else
    {
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
    try 
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(std::bad_cast&){}
    try 
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;

    }    
        catch(std::bad_cast&){}
    try 
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;

    }
        catch(std::bad_cast&){}
}
int main()
{
    Base *p = generate();
    Base *t =generate();
    identify(t);
    identify(p);
}