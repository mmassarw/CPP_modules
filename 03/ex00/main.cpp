#include "ClapTrap.hpp"
#include <limits.h>

int main( void ) {
   ClapTrap first("first");
   ClapTrap second("second");

    first.attack("sys");
    second.takeDamage(8);
    second.attack("dasda");
    second.beRepaired(1);
    return ( 0 );
}