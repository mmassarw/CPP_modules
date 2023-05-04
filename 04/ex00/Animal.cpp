#include "Animal.hpp"

Animal::Animal(){
	this->_type = "Animal";
	std::cout << this->_type << " has been constructed" << std::endl;
}

Animal::Animal(Animal const& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Animal&	Animal::operator=(Animal const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	this->_type = rhs._type;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal has been destroyed" << std::endl;
}

void	Animal::makeSound()const{
	std::cout << "* random animal noises *" << std::endl;
}

std::string	Animal::getType()const{
	return(this->_type);
}