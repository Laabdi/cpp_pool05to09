#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception> 
class Span
{
  private :
        unsigned int N;
        std::vector<int> array;
        public :
        Span();
        Span(unsigned int num);
        Span(const Span &oth);
        Span &operator=(const Span &oth);
        ~Span();
        class SpanFullException : public std::exception 
        {
            const char* what() const throw();
        };
        class NoSpanException : public std::exception 
        {
        public:
            const char* what() const throw();
        };
        //methodes
        void addNumber(int added);
        int shortestSpan();
        int longestSpan();
};