#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	private:
		std::string		_getType()const;

	public:
		FragTrap();
		FragTrap(std::string& name);
		FragTrap(FragTrap const& copy);
		FragTrap&operator=(FragTrap const& rhs);
		~FragTrap();

		void	highFiveGuys();
};

#endif