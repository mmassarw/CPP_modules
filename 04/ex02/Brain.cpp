#include "Brain.hpp"

Brain::Brain(){
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "...";
	std::cout << "Brain has been constructed" << std::endl;
}

Brain::Brain(Brain const& copy){
	std::cout << "Brain copy constructor called" << std::endl;
	delete [] this->_ideas;
	*this = copy;
}

Brain&	Brain::operator=(Brain const& rhs){
	std::cout << "Brain copy assignment operator called" << std::endl;
	delete [] this->_ideas;
	this->operator=(rhs);
	return (*this);
}

Brain::~Brain(){
	delete [] this->_ideas;
	std::cout << "Brain has been destroyed" << std::endl;
}