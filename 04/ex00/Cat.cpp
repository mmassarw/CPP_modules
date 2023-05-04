#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->_type = "Cat";
	std::cout << this->_type << " has been constructed" << std::endl;
}

Cat::Cat(Cat const& copy) : Animal(){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Cat&	Cat::operator=(Cat const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	this->_type = rhs._type;
	return (*this);
}

Cat::~Cat(){
	std::cout << this->_type << " has been destroyed" << std::endl;
}

void	Cat::makeSound()const{
	std::cout << "Meow" << std::endl;
}