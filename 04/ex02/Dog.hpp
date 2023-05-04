#ifndef DOG_HPP
# define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(Dog const& copy);
		Dog&operator=(Dog const& rhs);
		~Dog();

		void	makeSound()const;
		Brain*	getBrain();
};

#endif