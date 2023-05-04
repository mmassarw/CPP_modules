#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice " << this->_type << " has been constructed" << std::endl;
}

Ice::Ice(Ice const& copy) : AMateria() {
	// std::cout << "Ice " << this->_type << "copy constructor called" << std::endl;
	*this = copy;
}

Ice&	Ice::operator=(Ice const& rhs) {
	// std::cout << "Ice " << this->_type << " copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	this->_type = rhs._type;
	return (*this);
}

Ice::~Ice() {
	// std::cout << "Ice has been destroyed" << std::endl;
}

Ice* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
