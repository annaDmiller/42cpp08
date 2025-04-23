#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    std::list<int> l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(25);

    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found in vector: " << *it << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    try
    {
        std::list<int>::iterator it = easyfind(l, 10);
        std::cout << "Found in list: " << *it << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    try
    {
        std::deque<int>::iterator it = easyfind(d, 200);
        std::cout << "Found in deque: " << *it << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}