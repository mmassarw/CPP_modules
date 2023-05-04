#include "Fixed.hpp"

Fixed::Fixed(){
	this->setRawBits(0);
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number){
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(number << this->_fraction);
}

Fixed::Fixed(float const number){
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(number * (1 << this->_fraction)));
}

Fixed::Fixed(Fixed const &rhs){
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed &Fixed::operator=(Fixed const &rhs){
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

Fixed	Fixed::operator+( Fixed const& copy ) const {
	return ( Fixed( this->toFloat() + copy.toFloat() ));
}

Fixed	Fixed::operator-( Fixed const& copy ) const {
	return ( Fixed( this->toFloat() - copy.toFloat() ));
}

Fixed	Fixed::operator*( Fixed const& copy ) const {
	return ( Fixed( this->toFloat() * copy.toFloat() ));
}

Fixed	Fixed::operator/( Fixed const& copy ) const {
	return ( Fixed( this->toFloat() / copy.toFloat() ));
}

bool	Fixed::operator>( Fixed const& copy ) const {
	return ( this->toFloat() > copy.toFloat() );
}

bool	Fixed::operator<( Fixed const& copy ) const {
	return ( this->toFloat() < copy.toFloat() );
}

bool	Fixed::operator>=( Fixed const& copy ) const {
	return ( this->toFloat() >= copy.toFloat() );
}

bool	Fixed::operator<=( Fixed const& copy ) const {
	return ( this->toFloat() <= copy.toFloat() );
}

bool	Fixed::operator==( Fixed const& copy ) const {
	return ( this->toFloat() == copy.toFloat() );
}

bool	Fixed::operator!=( Fixed const& copy ) const {
	return ( this->toFloat() != copy.toFloat() );
}

int	Fixed::getRawBits()const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

Fixed	Fixed::operator++( void ) {
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++( int number ) {
	Fixed   ret;

	(void)number;
	ret.setRawBits( this->getRawBits() );
	this->_value++;
	return (ret);
}

Fixed	Fixed::operator--( void ) {
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--( int number ) {
	Fixed   ret;

	(void)number;
	ret.setRawBits( this->getRawBits() );
	this->_value--;
	return (ret);
}

std::ostream &operator<<(std::ostream &output, Fixed const &rhs){
	output << rhs.toFloat();
	return (output);
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

Fixed&	Fixed::min(Fixed& a, Fixed& b){
	return(a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b){
	return(a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b){
	return(a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){
	return(a > b ? a : b);
}
