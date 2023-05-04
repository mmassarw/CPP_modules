#ifndef AMATERIA_HPP
# define AMATERIA_HPP

// # include "ICharacter.hpp"
// # include "IMateriaSource.hpp"
# include <iostream>
# include <string>

class ICharacter;

class AMateria {
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(AMateria const& copy);
		AMateria&operator=(AMateria const& rhs);
		virtual ~AMateria();

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif