#include "Zombie.hpp"

int main( void ) {
    std::string name;

	std::cin >> name;
    std::cout << name << std::endl;
    Zombie zombi1(name);
    
    Zombie *zombi2 = newZombie("new " + name);
    delete zombi2;

    zombi1.randomChump("random " + name);
    return 0;
}