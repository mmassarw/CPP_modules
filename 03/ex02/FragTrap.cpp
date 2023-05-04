#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << this->_getType() << " " << this->_name << " constructed" << std::endl;
	_hp = 100;
	_energy = 50;
	_ad = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << this->_getType() << " " << this->_name << " constructed" << std::endl;
	_hp = 100;
	_energy = 50;
	_ad = 20;
}

FragTrap::FragTrap(FragTrap const& copy) : ClapTrap(copy){
	*this = copy;
}

FragTrap&	FragTrap::operator=(FragTrap const& rhs){
	if (this == &rhs)
		return;
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_ad = rhs._ad;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << this->_getType() << " " << this->_name << " destroyed" << std::endl;
}

std::string	FragTrap::_getType()const{
	return ("FragTrap");
}

void	FragTrap::highFiveGuys(){
	std::cout << this->_getType() << " " << this->_name << " offers to highfive to increase morale by 5 points" << std::endl;
}