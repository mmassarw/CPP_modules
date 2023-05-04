#include "IMateriaSource.hpp"
#include "AMateria.hpp"

IMateriaSource::IMateriaSource() {
	// std::cout << "IMateriaSource has been constructed" << std::endl;
	for (int i = 0; i < 4; i++){
		this->_bookOfMaterial[i] = NULL;
	}
}

IMateriaSource::IMateriaSource(IMateriaSource const& copy) {
	// std::cout << "IMateriaSource copy constructor called" << std::endl;
	*this = copy;
}

IMateriaSource&	IMateriaSource::operator=(IMateriaSource const& rhs) {
	// std::cout << "IMateriaSource copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	for (int i = 0; i < 4; i++){
		if (this->_bookOfMaterial[i])
			delete this->_bookOfMaterial[i];
		this->_bookOfMaterial[i] = rhs._bookOfMaterial[i];
	}
	return (*this);
}

IMateriaSource::~IMateriaSource() {
	// std::cout << "IMateriaSource has been destroyed" << std::endl;
	for (int i = 0; i < 4; i++){
		if (this->_bookOfMaterial[i])
			delete this->_bookOfMaterial[i];
	}
}