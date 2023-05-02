#include "HumanB.hpp"

HumanB::HumanB(std::string string){
	this->weapon = NULL;
	this->name = string;
	std::cout << "HumanB " << this->name << " has been constructed." << std::endl;
}

HumanB::~HumanB(){
	std::cout << "HumanB " << this->name << " has been destroyed." << std::endl;
}

void	HumanB::attack(){
	if(this->weapon != NULL)
		std::cout << this->name << " has attacked with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " is not holding a weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &heldItem){
	this->weapon = &heldItem;
}