#include "ICharacter.hpp"

ICharacter::ICharacter() : _name("default") {
	// std::cout << "ICharacter " << this->_name << " has been constructed" << std::endl;
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
		this->_inventoryStatus[i] = false;
	}
}

ICharacter::ICharacter(std::string const& name) : _name(name) {
	// std::cout << "ICharacter " << this->_name << " has been constructed" << std::endl;
	for (int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
		this->_inventoryStatus[i] = false;
	}
}

ICharacter::ICharacter(ICharacter const& copy) {
	// std::cout << "ICharacter " << this->_name << "copy constructor called" << std::endl;
	*this = copy;
}

ICharacter&	ICharacter::operator=(ICharacter const& rhs) {
	// std::cout << "ICharacter " << this->_name << " copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

ICharacter::~ICharacter() {
	// std::cout << "ICharacter has been destroyed" << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}