#include "RPN.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Usage: " << av[0] << " 'expression'" << std::endl;
		return 0;
	}
    try {
        double result = RPN::calculator(av[1]);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error" << std::endl;
    }

    return 0;
}