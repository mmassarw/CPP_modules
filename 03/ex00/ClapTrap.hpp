#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_ad;

		std::string		_getType()const;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& copy);
		ClapTrap&operator=(ClapTrap const& rhs);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif