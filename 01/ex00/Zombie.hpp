#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class	Zombie {
	public:
		Zombie(std::string);
		~Zombie();

		Zombie* newZombie(std::string);
		void	randomChump(std::string);

	private:
		std::string	name;

		void	announce();
};

Zombie* newZombie(std::string);
void	randomChump(std::string);

#endif