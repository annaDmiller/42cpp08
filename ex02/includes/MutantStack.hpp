#pragma once

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack
: public std::stack<T, Container>
{
    public:
        MutantStack(void) : std::stack<T, Container>()
        {
            return ;
        }

        MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
        {
            return ;
        }

        MutantStack& operator=(const MutantStack& other)
        {
            if (this == &other)
                return (*this);
            
            this->std::stack<T, Container>::operator=(other);
            return (*this);
        }

        ~MutantStack(void)
        {
            return ;
        }

        typedef typename std::stack<T, Container>::container_type::iterator                 iterator;
        typedef typename std::stack<T, Container>::container_type::const_iterator           const_iterator;
        typedef typename std::stack<T, Container>::container_type::reverse_iterator         reverse_iterator;
        typedef typename std::stack<T, Container>::container_type::const_reverse_iterator   const_reverse_iterator;
        

        iterator begin(void)
        {
            return (this->c.begin());
        }
        iterator end(void)
        {
            return (this->c.end());
        }

        const_iterator cbegin(void) const
        {
            return (this->c.begin());
        }
        const_iterator cend(void) const
        {
            return (this->c.end());
        }

        reverse_iterator rbegin(void)
        {
            return (this->c.rbegin());
        }
        reverse_iterator rend(void)
        {
            return (this->c.rend());
        }

        const_reverse_iterator rbegin(void) const
        {
            return (this->c.rbegin());
        }
        const_reverse_iterator rend(void) const
        {
            return (this->c.rend());
        }
};