#ifndef CAT_HPP
# define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal{
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat(Cat const& copy);
		Cat&operator=(Cat const& rhs);
		~Cat();

		void	makeSound()const;
};

#endif