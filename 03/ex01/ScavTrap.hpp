#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:
		std::string		_getType()const;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& copy);
		ScavTrap&operator=(ScavTrap const& rhs);
		~ScavTrap();

		void	guardGate();
};

#endif