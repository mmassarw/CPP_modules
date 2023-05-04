#include "Zombie.hpp"

void	randomChump(std::string string){
	Zombie zombie(string);
	zombie.announce();
}