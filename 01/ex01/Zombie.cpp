#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Zombie default constructor has been called." << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
};

void	Zombie::setName(std::string string){
	this->name = string;
}

void	Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}