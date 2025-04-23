#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int num);

class ValueNotFoundException : public std::exception
{
    virtual const char* what() const throw()
    {
        return ("Value is not found in the container");
    }
};

#include "easyfind.tpp"

#endif