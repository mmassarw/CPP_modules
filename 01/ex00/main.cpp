#include "Zombie.hpp"

int main( void ) {
    std::string name;

	std::cin >> name;
	name = "";
    Zombie zombi1(name);
    
    Zombie *zombi2 = newZombie(name);
    delete zombi2;

    zombi1.randomChump(name);
    return 0;
}