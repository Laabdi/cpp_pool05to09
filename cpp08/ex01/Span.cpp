#include "Span.hpp"

Span::Span() : N(0){}
Span::Span(unsigned int num) : N(num)
{
    this->array.reserve(N);
}
Span::Span(const Span &oth)
{
    N = oth.N;
    array = oth.array;
}
Span &Span::operator=(const Span &oth)
{
    if(this != &oth)
    {
        N = oth.N;
        array = oth.array;
    }
    return *this;
}
const char* Span::SpanFullException::what()const throw()
{
    return("Span is full\n");
}
const char* Span::NoSpanException::what()const throw()
{
    return("No span can be found (not enough numbers)\n");
}

void Span::addNumber(int added)
{
    if (this->array.size() >= this->N)
        throw Span::SpanFullException();    
    this->array.push_back(added);
}
int Span::shortestSpan()
{
    std::vector<int> tmp = this->array;
    std::sort(tmp.begin(),tmp.end());
}
int Span::longestSpan()
{
    if (this->array.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> tmp = this->array;
    std::sort(tmp.begin(),tmp.end());
    int min = tmp[1] - tmp[0];
    return min;
}