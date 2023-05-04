#include "Zombie.hpp"

int main( void ) {
	Zombie *zomb = newZombie( "Hadi" );
	zomb->announce();
	randomChump("randomChump");
	delete zomb;
}