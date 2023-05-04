#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <iostream>
# include <string>

class ICharacter {
	protected:
		std::string	_name;
		AMateria*	_inventory[4];
		bool		_inventoryStatus[4];

	public:
		ICharacter();
		ICharacter(std::string const& name);
		ICharacter(ICharacter const& copy);
		ICharacter&operator=(ICharacter const& rhs);
		virtual ~ICharacter();

		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif