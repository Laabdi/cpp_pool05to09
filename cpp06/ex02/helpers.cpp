#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
    srand (time(NULL));
    int random = rand() % 3;
    if(random == 0)
    {
        A *test;
        return(test);
    }
    if(random == 1)
    {
         B *test1;
        return(test1);
    }
    if(random == 2)
    {
        C *test2;
        return(test2);
    }

}
void identify(Base* p)
{
    std::cout <<  << std::endl;
}
void identify(Base& p)
{

}
int main()
{
    generate();
}