#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	// std::cout << "MateriaSource has been constructed" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& copy) : IMateriaSource() {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& rhs) {
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this == &rhs)
		return;
	for (int i = 0; i < 4; i++){
		if (this->_bookOfMaterial[i])
			delete this->_bookOfMaterial[i];
		this->_bookOfMaterial[i] = rhs._bookOfMaterial[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource has been destroyed" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m) {
	for(int i = 0; i < 4; i++){
		if (!this->_bookOfMaterial[i]){
			this->_bookOfMaterial[i] = m;
			return;
		}
	}
	std::cout << "Book is full" << std::endl;
	delete m;
	return;
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for(int i = 0; i < 4; i++){
		if (this->_bookOfMaterial[i]){
			if (this->_bookOfMaterial[i]->getType() == type)
				return (this->_bookOfMaterial[i]->clone());
		}
	}
	std::cout << "No matching material" << std::endl;
	return (NULL);
}
