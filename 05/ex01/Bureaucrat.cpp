#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
	this->setGrade(grade);
	this->setName(name);
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs) {
    *this = rhs;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	if (this != &rhs) {
		this->setGrade(rhs.getGrade());
		this->setName(rhs.getName());
	}
    return (*this);
}

Bureaucrat::~Bureaucrat() {
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

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int         Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void        Bureaucrat::incrementGrade(void) {
	if (this->getGrade() >= 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void        Bureaucrat::decrementGrade(void) {
	if (this->getGrade() <= 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void        Bureaucrat::signForm(Form& form) const {
	std::cout << this->_name << " signed " << form.getName();
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &rhs) {
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (output);
}