#include "Zombie.hpp"

int main( void ) {
    std::string name;

	std::cin >> name;
    int n = 0;
    Zombie *zombies = zombieHorde(n, name);
    for (int i = 0; i < n; i++)
        zombies[i].announce();
    delete [] zombies;
    return 0;
}