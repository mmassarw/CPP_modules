#include "HumanA.hpp"

HumanA::HumanA(std::string string, Weapon &heldItem){
	this->name = string;
	this->weapon = &heldItem;
	std::cout << "HumanA " << this->name << " armed with " << this->weapon->getType() << " has been constructed." << std::endl;
}

HumanA::~HumanA(){
	std::cout << "HumanA " << this->name<< " has been destroyed." << std::endl;
}

void	HumanA::attack(){
	if(this->weapon->getType() != "")
		std::cout << this->name << " has attacked with " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " is not holding a weapon" << std::endl;
}