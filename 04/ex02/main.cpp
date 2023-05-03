#include "Kingdom.hpp"

int main(void)
{
    Animal * i = new Cat();
    Animal * j = new Dog();

    std::cout << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;

    *i = *j;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << std::endl;

    i->makeSound();
    j->makeSound();
    std::cout << std::endl;

    delete i;
    delete j;
}