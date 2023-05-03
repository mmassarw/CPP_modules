#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->_brain = new Brain();
	this->_type = "Cat";
	std::cout << this->_type << " has been constructed" << std::endl;
}

Cat::Cat(Cat const& copy) : Animal(){
	if (this->_brain)
		delete this->_brain;
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Cat&	Cat::operator=(Cat const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this->_brain)
		delete this->_brain;
	this->operator=(rhs);
	return (*this);
}

Cat::~Cat(){
	if (this->_brain)
		delete this->_brain;
	std::cout << this->_type << " has been destroyed" << std::endl;
}

void	Cat::makeSound()const{
	std::cout << "Meow" << std::endl;
}