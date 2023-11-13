#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(75) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
    std::cout << "Constructor called" << std::endl;
	this->setGrade(grade);
	this->setName(name);
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

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int         Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void        Bureaucrat::incrementGrade(void) {
	if (this->getGrade() >= 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade++;
}

void        Bureaucrat::decrementGrade(void) {
	if (this->getGrade() <= 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The maximum grade is 150");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The minimum grade is 1");
}

void        Bureaucrat::setName(std::string name) {
	this->_name = name;
}

void        Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &rhs) {
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (output);
}