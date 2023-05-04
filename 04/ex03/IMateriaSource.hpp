#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

// # include "AMateria.hpp"
// # include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria;

class IMateriaSource {
	protected:
		AMateria*	_bookOfMaterial[4];

	public:
		IMateriaSource();
		IMateriaSource(std::string const& type);
		IMateriaSource(IMateriaSource const& copy);
		IMateriaSource&operator=(IMateriaSource const& rhs);
		virtual ~IMateriaSource();

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif