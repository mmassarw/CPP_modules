#include "Fixed.hpp"

Fixed::Fixed(){
	this->setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number){
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number << this->_fraction);
}

Fixed::Fixed(float const number){
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(number * (1 << this->_fraction)));
}

Fixed::Fixed(Fixed const &rhs){
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed &Fixed::operator=(Fixed const &rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &output, Fixed const &rhs){
	output << rhs.toFloat();
	return (output);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits()const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const number){
	this->_value = number;
}

float	Fixed::toFloat()const{
	return ((float) this->_value / (1 << this->_fraction));
}

int		Fixed::toInt()const{
	return (this->_value >> this->_fraction);
}