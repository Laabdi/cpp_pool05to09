#pragma once
#include <stack>
#include <deque>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack<T>& src);
    MutantStack<T>& operator=(const MutantStack<T>& src);
    ~MutantStack();
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

