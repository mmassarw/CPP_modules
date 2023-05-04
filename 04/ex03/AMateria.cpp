#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("default") {
	// std::cout << "AMateria " << this->_type << " has been constructed" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
	// std::cout << "AMateria " << this->_type << " has been constructed" << std::endl;
}

AMateria::AMateria(AMateria const& copy) {
	// std::cout << "AMateria " << this->_type << "copy constructor called" << std::endl;
	*this = copy;
}

AMateria&	AMateria::operator=(AMateria const& rhs) {
	// std::cout << "AMateria " << this->_type << " copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria() {
	// std::cout << "AMateria has been destroyed" << std::endl;
}

std::string const& AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	(void) target;
	std::cout << "* you are not supposed to be able to see this *" << std::endl;
}
