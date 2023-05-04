#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class	Zombie {
	public:
		Zombie();
		~Zombie();

		void	announce();
		void	setName(std::string);

	private:
		std::string	name;

};

Zombie* zombieHorde(int, std::string);

#endif