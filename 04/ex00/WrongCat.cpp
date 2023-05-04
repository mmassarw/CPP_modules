#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->_type = "WrongCat";
	std::cout << this->_type << " has been constructed" << std::endl;
}

WrongCat::WrongCat(WrongCat const& copy) : WrongAnimal(){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat&	WrongCat::operator=(WrongCat const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << this->_type << " has been destroyed" << std::endl;
}

void	WrongCat::makeSound()const{
	std::cout << "* Human meowing noises *" << std::endl;
}