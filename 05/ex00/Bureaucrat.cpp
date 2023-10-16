#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
	this->setGrade(rhs.getGrade());
	this->setName(rhs.getName());
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat	Bureaucrat::operator++( void ) {
	this->_grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++( int number ) {
	Bureaucrat   ret;

	(void)number;
	ret.setGrade( this->getGrade() );
	this->_grade--;
	return (ret);
}

Bureaucrat	Bureaucrat::operator--( void ) {
	this->_grade++;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--( int number ) {
	Bureaucrat   ret;

	(void)number;
	ret.setGrade( this->getGrade() );
	this->_grade++;
	return (ret);
}

std::string	Bureaucrat::getName(void) {
	return (this->_name);
}

int         Bureaucrat::getGrade(void) {
	return (this->_grade);
}
void        Bureaucrat::setName(std::string name) {
	this->_name = name;
}

void        Bureaucrat::setGrade(int grade) {
	this->_grade;
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &rhs){
	output << rhs->getName() << ", bureaucrat grade " << rhs->getGrade();
	return (output);
}