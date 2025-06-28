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
    for (std::vector<int>::const_iterator iter = other._numbers.begin(); iter != other._numbers.end(); iter++)
    {
        this->_numbers.push_back(*iter);
    }
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
        this->_size = other._size;
        this->_numbers.clear();

        for (std::vector<int>::const_iterator iter = other._numbers.begin(); iter != other._numbers.end(); iter++)
        {
            this->_numbers.push_back(*iter);
        }
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (this->_numbers.size() + 1 > this->_size)
        throw SpanIsFullException();
    this->_numbers.push_back(number);
    return ;
}

unsigned int Span::shortestSpan(void)
{
    if (this->_numbers.size() == 0)
        throw SpanIsEmptyException();
    if (this->_numbers.size() == 1)
        throw SpanSmallForDistanceCalculationException();
    
    std::sort(this->_numbers.begin(), this->_numbers.end());

    unsigned int dist = *std::max_element(this->_numbers.begin(), this->_numbers.end());
    unsigned int temp = 0;
    for (unsigned int ind = 1; ind < static_cast<unsigned int>(this->_numbers.size()); ind++)
    {
        temp = abs(this->_numbers[ind] - this->_numbers[ind - 1]);
        if (dist > temp)
            dist = temp;
    }
    return (dist);
}

unsigned int Span::longestSpan(void)
{
    if (this->_numbers.size() == 0)
        throw SpanIsEmptyException();
    if (this->_numbers.size() == 1)
        throw SpanSmallForDistanceCalculationException();

    std::sort(this->_numbers.begin(), this->_numbers.end());

    int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());

    return (max - min);
}

const char* Span::SpanIsFullException::what() const throw()
{
    return ("Can't add number to the span - the Span is full");
}

const char* Span::NotEnoughPlaceScopeInsertException::what() const throw()
{
    return ("Can't insert a range of numbers - not enough space in the Span");  
}

const char* Span::SpanIsEmptyException::what() const throw()
{
    return ("Can't calculate the distance - the Span is empty");
}

const char* Span::SpanSmallForDistanceCalculationException::what() const throw()
{
    return ("Can't calculate the distance - there is only one number in Span");
}