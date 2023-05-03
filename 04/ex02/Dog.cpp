#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->_brain = new Brain();
	this->_type = "Dog";
	std::cout << this->_type << " has been constructed" << std::endl;
}

Dog::Dog(Dog const& copy) : Animal(){
	std::cout << "Copy constructor called" << std::endl;
	if (this->_brain)
		delete this->_brain;
	*this = copy;
}

Dog&	Dog::operator=(Dog const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this->_brain)
		delete this->_brain;
	this->operator=(rhs);
	return (*this);
}

Dog::~Dog(){
	if (this->_brain)
		delete this->_brain;
	std::cout << this->_type << " has been destroyed" << std::endl;
}

void	Dog::makeSound()const{
	std::cout << "Bark" << std::endl;
}