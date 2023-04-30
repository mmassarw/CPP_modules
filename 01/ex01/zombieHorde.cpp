#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string string){
	Zombie	*zombies = new Zombie[n];
	for (int i = 0; i < n; i++)  {
		zombies[i].setName(string);
	}
	return (zombies);
}