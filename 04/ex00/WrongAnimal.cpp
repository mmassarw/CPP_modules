#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->_type = "WrongAnimal";
	std::cout << this->_type << " has been constructed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	this->operator=(rhs);
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Wrong Animal has been destroyed" << std::endl;
}

void	WrongAnimal::makeSound()const{
	std::cout << "* random human noises *" << std::endl;
}

std::string	WrongAnimal::getType()const{
	return(this->_type);
}