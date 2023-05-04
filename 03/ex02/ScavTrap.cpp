#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << this->_getType() << " " << this->_name << " constructed" << std::endl;
	_hp = 100;
	_energy = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << this->_getType() << " " << this->_name << " constructed" << std::endl;
	_hp = 100;
	_energy = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(ScavTrap const& copy) : ClapTrap(copy){
	*this = copy;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs){
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_ad = rhs._ad;
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << this->_getType() << " " << this->_name << " destroyed" << std::endl;
}

std::string	ScavTrap::_getType()const{
	return ("ScavTrap");
}

void	ScavTrap::guardGate(){
	std::cout << this->_getType() << " " << this->_name << " is in gate keeper mode" << std::endl;
}