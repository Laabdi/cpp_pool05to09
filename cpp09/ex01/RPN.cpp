#include "RPN.hpp"


std::stack<int> RPN::do_operations(std::string input)
{
    std::stack<int> t_stack;
    
    for(size_t i = 0; i < input.length(); i++)
    {
        if(input[i] == ' ')
            continue;  
        if(isdigit(input[i]))
            t_stack.push(input[i] - '0');
        
        else if(input[i] == '+' || input[i] == '-' || 
                input[i] == '*' || input[i] == '/')
        {
            if(t_stack.size() < 2)
            {
                std::cerr << "Error: not enough operands" << std::endl;
                exit(1);
            }
            int n2 = t_stack.top(); t_stack.pop();
            int n1 = t_stack.top(); t_stack.pop();

            if(input[i] == '+')
                t_stack.push(n1 + n2);
            else if(input[i] == '-')
                t_stack.push(n1 - n2);
            else if(input[i] == '/')
            {
                if(n2 == 0)
                {
                    std::cerr << "error divided by zero" << std::endl;
                    exit(1);
                }
                t_stack.push(n1 / n2);
            }
            else if(input[i] == '*')
                t_stack.push(n1 * n2);
        }
        else
        {
            std::cerr << "Error: invalid character" << std::endl;
            exit(1);
        }
    }
    
    return t_stack;
}

void    print_stack(std::stack<int> &t)
{
    while(!t.empty())
    {
        std::cout << t.top() << std::endl;
        t.pop();
    }
}
int main(int ac, char **av)
{
    RPN test;

    if(ac == 2)
    {
        std::stack<int> result = test.do_operations(av[1]);
        
        if(result.size() == 1)
            std::cout << result.top() << std::endl;
        else if(result.empty())
            std::cerr << "Error: empty result" << std::endl;
        else
            std::cerr << "Error: too many operands" << std::endl;
    }
    else
        std::cerr << "Error: wrong number of arguments" << std::endl;
    
    return 0;
}