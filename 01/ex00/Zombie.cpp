#include "Zombie.hpp"

Zombie::Zombie(std::string string){
	std::cout << "Zombie " << this->name << " has been called." << std::endl;
	if (string.empty())
		return;
	this->name = string;
	this->announce();
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
};

void	Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}