#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const& copy);
		WrongAnimal&operator=(WrongAnimal const& rhs);
		virtual ~WrongAnimal();

		virtual void	makeSound()const;
		std::string		getType()const;
};

#endif