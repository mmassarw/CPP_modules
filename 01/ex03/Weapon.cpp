#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(std::string string){
	this->type = string;
	std::cout << "Weapon " << this->type << " has been constructed." << std::endl;
}

Weapon::~Weapon(){
	std::cout << "Weapon " << this->type << " has been destroyed." << std::endl;
}

void	Weapon::setType(std::string newtype){
	this->type = newtype;
}

const std::string& Weapon::getType(){
	return (this->type);
}