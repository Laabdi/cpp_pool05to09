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
    if (this->array.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> tmp = this->array;
    std::sort(tmp.begin(), tmp.end());
    int min_span = tmp[1] - tmp[0];
    for (size_t i = 2; i < tmp.size(); ++i)
    {
        if (tmp[i] - tmp[i-1] < min_span)
        {
            min_span = tmp[i] - tmp[i-1];
        }
    }
    return min_span;
}

int Span::longestSpan()
{
    if (this->array.size() < 2)
        throw Span::NoSpanException();
    std::vector<int> tmp = this->array;
    std::sort(tmp.begin(),tmp.end());
        return (tmp.back() - tmp.front());
}
void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(array.size() + std::distance(begin,end) > N)
    {
        throw SpanFullException();
    }
    array.insert(array.end(),begin,end);
}