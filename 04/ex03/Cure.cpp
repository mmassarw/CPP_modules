#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure " << this->_type << " has been constructed" << std::endl;
}

Cure::Cure(Cure const& copy) : AMateria() {
	// std::cout << "Cure " << this->_type << "copy constructor called" << std::endl;
	*this = copy;
}

Cure&	Cure::operator=(Cure const& rhs) {
	// std::cout << "Cure " << this->_type << " copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	this->_type = rhs._type;
	return (*this);
}

Cure::~Cure() {
	// std::cout << "Cure has been destroyed" << std::endl;
}

Cure* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
