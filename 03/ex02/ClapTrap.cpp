#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hp(10), _energy(10), _ad(10){
	std::cout << this->_getType() << " " << this->_name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _ad(10){
	std::cout << this->_getType() << " " << this->_name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& copy){
	*this = copy;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs){
	if (this == &rhs)
		return;
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_ad = rhs._ad;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << this->_getType() << " " << this->_name << " destroyed" << std::endl;
}

std::string	ClapTrap::_getType()const{
	return ("ClapTrap");
}

void	ClapTrap::attack(const std::string& target){
	if (!this->_hp){
		std::cout << this->_getType() << " " << this->_name << " is dead" << std::endl;
		return;
	} else if (!this->_energy){
		std::cout << this->_getType() << " " << this->_name << " is out of energy" << std::endl;
		return;
	}
	std::cout << this->_getType() << " " << this->_name << " is attacking " << target << ", causeing " << this->_ad << " damage" << std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_hp <= amount){
		std::cout << this->_getType() << " " << this->_name << " is dead" << std::endl;
		this->_hp = 0;
		return;
	}
	std::cout << this->_getType() << " " << this->_name << " took damage for " << amount << std::endl;
	this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (!this->_hp){
		std::cout << this->_getType() << " " << this->_name << " is dead" << std::endl;
		return;
	} else if (!this->_energy){
		std::cout << this->_getType() << " " << this->_name << " is out of energy" << std::endl;
		return;
	}
	std::cout << this->_getType() << " " << this->_name << " recovered " << amount << " health points" << std::endl;
	this->_hp += amount;
	this->_energy--;
}
