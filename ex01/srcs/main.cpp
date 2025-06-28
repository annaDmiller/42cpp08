#include "Span.hpp"

int main(void)
{
    Span sp = Span(10);

    std::cout << "TESTING SPAN CALCULATION EXCEPTIONS" << std::endl;
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    sp.addNumber(6);

    try
    {
        std::cout << sp.shortestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << std::endl;
    std::cout << "TESTING SPAN CALCULATION" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::vector<int> new_vec;
    new_vec.push_back(-15);
    new_vec.push_back(1);
    new_vec.push_back(0);
    new_vec.push_back(10);
    new_vec.push_back(3);

    std::cout << "TESTING MULTIPLE NUMBERS INSERT AND SPAN CALCULATION" << std::endl;
    sp.addMultNumbers(new_vec.begin(), new_vec.end());

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::vector<int> test(2);
    std::cout << "TESTING ADDING NUMBER EXCEPTIONS" << std::endl;
    try
    {
        sp.addMultNumbers(test.begin(), test.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        sp.addNumber(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    std::cout << "GOING CRAZZZZZZZY" << std::endl;
    Span big_test = Span(10000);
    std::srand(std::time(0));

    for (int ind = 0; ind < 10000; ind++)
    {
        big_test.addNumber(std::rand() % (400001) - 200000);
    }
    std::cout << "Shortest span - " << big_test.shortestSpan() << std::endl;
    std::cout << "Longest span - " << big_test.longestSpan() << std::endl;

    return 0;
}