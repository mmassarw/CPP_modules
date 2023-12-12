#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    Span sp(5);
    sp.addNumber(2147483647);
    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    sp.addNumber(-2147483648);
    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
	try {
		sp.addNumber(1);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    const size_t size = 10000;
    Span big(size);

    std::srand(std::time(NULL));

    for (size_t i = 0; i < size; ++i) {
        big.addNumber(std::rand() % 100000);
    }

    try {
        std::cout << "Shortest Span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << big.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}