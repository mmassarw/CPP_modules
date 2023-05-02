#include "Zombie.hpp"

Zombie::Zombie(std::string string){
	if (string.empty())
		return;
	this->name = string;
	std::cout << "Zombie " << this->name << " has been called." << std::endl;
	this->announce();
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
};

void	Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}