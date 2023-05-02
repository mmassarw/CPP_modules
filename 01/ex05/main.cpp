#include "Harl.hpp"

int	main(int ac, char** av){
	if (ac != 2){
		std::cout << "Only 1 prompt at a time" << std::endl;
	}
	Harl	complainer;
	complainer.complain(av[1]);
}