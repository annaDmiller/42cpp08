#pragma once

#include <iostream>
#include <algorithm>
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
        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const;

    class SpanIsFullException : public std::exception
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