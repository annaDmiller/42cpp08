#include "MutantStack.hpp"
#include <list>

int main(void)
{
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "TESTING MUTANTSTACK" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top value - " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Size of the stack after poping - " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
        std::cout << "Size of the copied stack from the MutantStack - " << s.size() << std::endl;

        MutantStack<int>::const_iterator cit = mstack.cbegin();
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();

        std::cout << "Printing values of other types of iterators:" << std::endl;
        std::cout << "Const begin iter " << *cit << std::endl;
        std::cout << "Reverse begin iter " << *rit << std::endl;
        std::cout << "Const reverse begin iter " << *crit << std::endl;
        
        *rit = 10;
        std::cout << "Reverse iter value after change " << *rit << std::endl;
    }
    std::cout << std::endl;
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "TESTING MUTANTSTACK WITH LIST CONTAINER" << std::endl;
    {
        MutantStack<int, std::list<int> > mstack_list;

        mstack_list.push(5);
        mstack_list.push(17);

        std::cout << "Top value - " << mstack_list.top() << std::endl;

        mstack_list.pop();

        std::cout << "Size of the stack after poping - " << mstack_list.size() << std::endl;

        mstack_list.push(3);
        mstack_list.push(5);
        mstack_list.push(737);
        mstack_list.push(0);

        std::list<int>::iterator it = mstack_list.begin();
        std::list<int>::iterator ite = mstack_list.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int, std::list<int> > s(mstack_list);
        std::cout << "Size of the copied stack from the MutantStack - " << s.size() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "_________________________________________________________________________" << std::endl;
    std::cout << "TESTING LIST - to compare behavior" << std::endl;
    {
        std::list<int> my_list;

        my_list.push_back(5);
        my_list.push_back(17);

        std::cout << "Last value of the list - " << my_list.back() << std::endl;

        my_list.pop_back();

        std::cout << "Size of the list after poping last element - " << my_list.size() << std::endl;

        my_list.push_back(3);
        my_list.push_back(5);
        my_list.push_back(737);
        my_list.push_back(0);

        std::list<int>::iterator it = my_list.begin();
        std::list<int>::iterator ite = my_list.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return 0;
}