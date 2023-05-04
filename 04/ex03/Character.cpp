#include "Character.hpp"

Character::Character() : ICharacter() {
	// std::cout << "Character " << this->_name << " has been constructed" << std::endl;
}

Character::Character(std::string const& name) : ICharacter(name) {
	// std::cout << "Character " << this->_name << " has been constructed" << std::endl;
}

Character::Character(Character const& copy) : ICharacter(){
	// std::cout << "Character " << this->_name << "copy constructor called" << std::endl;
	*this = copy;
}

Character&	Character::operator=(Character const& rhs) {
	// std::cout << "Character " << this->_name << " copy assignment operator called" << std::endl;
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

Character::~Character() {
	// std::cout << "Character has been destroyed" << std::endl;
}

std::string const& Character::getName() const{
	return (this->_name);
}

void Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++){
		if (!this->_inventoryStatus[i]){
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = m;
			this->_inventoryStatus[i] = true;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	return;
}

void Character::unequip(int idx){
	if (idx >= 0 && idx <= 3){
		if (this->_inventoryStatus[idx])
			this->_inventoryStatus[idx] = false;
		else
			std::cout << "Inventory slot already unequiped" << std::endl;
	} else
		std::cout << "Inventory slot out of range" << std::endl;
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx <= 3){
		if (this->_inventoryStatus[idx])
			this->_inventory[idx]->use(target);
		else
			std::cout << "Slot unequiped" << std::endl;
	} else
		std::cout << "Inventory slot out of range" << std::endl;
}
