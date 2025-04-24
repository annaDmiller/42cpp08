#include "Span.hpp"

Span::Span(void) : _size(0)
{
    return ;
}

Span::Span(unsigned int N) : _size(N)
{
    return ;
}

Span::Span(const Span& other) : _size(other._size)
{
    return ;
}

Span::~Span(void)
{
    return ;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {

    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (this->_numbers.size() > this->_size)
        throw SpanIsFullException();
    this->_numbers.push_back(number);
    return ;
}

unsigned int Span::shortestSpan(void) const
{
    if (this->_numbers.size() == 0)
        throw SpanIsEmptyException();
    if (this->_numbers.size() == 1)
        throw SpanSmallForDistanceCalculationException();
    
    unsigned int dist = __UINT32_MAX__;
    unsigned int temp = 0;
    for (unsigned int ind = 1; ind < static_cast<unsigned int>(this->_numbers.size()); ind++)
    {
        temp = abs(this->_numbers[ind] - this->_numbers[ind - 1]);
        if (dist > temp)
            dist = temp;
    }
    return (dist);
}

unsigned int Span::longestSpan(void) const
{
    if (this->_numbers.size() == 0)
        throw SpanIsEmptyException();
    if (this->_numbers.size() == 1)
        throw SpanSmallForDistanceCalculationException();

    unsigned int dist = 0;
    unsigned int temp = 0;
    for (unsigned int ind = 1; ind < static_cast<unsigned int>(this->_numbers.size()); ind++)
        {
            temp = abs(this->_numbers[ind] - this->_numbers[ind - 1]);
            if (dist < temp)
                dist = temp;
        }
    return (dist);
}

const char* Span::SpanIsFullException::what() const throw()
{
    return ("Can't add number to the span - the Span is full");
}

const char* Span::SpanIsEmptyException::what() const throw()
{
    return ("Can't calculate the distance - the Span is empty");
}

const char* Span::SpanSmallForDistanceCalculationException::what() const throw()
{
    return ("Can't calculate the distance - there is only one number in Span");
}