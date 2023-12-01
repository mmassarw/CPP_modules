#include <iostream>
#include "iter.hpp"

template <typename T> void print(T &x) {
	std::cout << x << " ";
}

int main (void) {
	int			numbers[] = { 420, 69, 34, 1337, 80085 };
	std::string	words[] = { "Shrek", "is", "love" };
	
	::iter(numbers, 5, print);
	std::cout << std::endl;
	::iter(words, 3, print);
	std::cout << std::endl;
	::iter(words[0].c_str(), 5, print);
	std::cout << std::endl;
	return 0;
}