#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain{
	private:
		std::string*	_ideas;
	public:
		Brain();
		Brain(Brain const& copy);
		Brain&operator=(Brain const& rhs);
		virtual ~Brain();
};

#endif