#include "Serializer.hpp"

int main (void) {
	Data *original = new Data;
	Data *returned;

	original->something = 8;
	original->words = "these are words";
	original->c = 'C';
	original->f = 42.42f;
	original->d = 24.24;

	returned = Serializer::deserialize(Serializer::serialize(original));
	
	std::cout << "~~~~~ORGINAL~~~~~~\n";
	std::cout << original->something << std::endl;
	std::cout << original->words << std::endl;
	std::cout << original->c << std::endl;
	std::cout << original->f << std::endl;
	std::cout << original->d << std::endl;

	std::cout << "~~~~~RETURNED~~~~~~\n";
	std::cout << returned->something << std::endl;
	std::cout << returned->words << std::endl;
	std::cout << returned->c << std::endl;
	std::cout << returned->f << std::endl;
	std::cout << returned->d << std::endl;

	std::cout << "~~~~~MEMORY~~~~~~\n";
	std::cout << original << std::endl;
	std::cout << returned << std::endl;
	if (original == returned)
		std::cout << "Success!\n";
	delete original;
}