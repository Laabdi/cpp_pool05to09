#include <iostream>
#include <stack>

class RPN
{
    private :
        std::stack<int> test;
    public :
    std::stack<int> do_operations(std::string input);
    std::stack<int> get_stack(){return test;}
    void set_stack(std::stack<int> t){test = t;}

};