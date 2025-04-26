#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <functional>
#include <exception>
#include <vector>
#include <limits>

class Span
{
    private:
        unsigned int        _size;
        std::vector<int>    _numbers;

    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span& other);
        ~Span(void);
        Span& operator=(const Span& other);

        void addNumber(int number);
        template <typename Iter> void addMultNumbers(Iter first, Iter last);        
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);

    class SpanIsFullException : public std::exception
    {
        virtual const char* what() const throw();
    };

    class NotEnoughPlaceScopeInsertException : public std::exception
    {
        virtual const char* what() const throw();

    };

    class SpanIsEmptyException : public std::exception
    {
        virtual const char* what() const throw();
    };

    class SpanSmallForDistanceCalculationException : public std::exception
    {
        virtual const char* what() const throw();
    };
};

#include "Span.tpp"

#endif