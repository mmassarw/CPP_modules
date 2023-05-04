#ifndef CAT_HPP
# define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(Cat const& copy);
		Cat&operator=(Cat const& rhs);
		~Cat();

		void	makeSound()const;
		Brain*	getBrain();
};

#endif