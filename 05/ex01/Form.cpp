#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _isSigned(false) {
	this->setName(name);
	this->setGradeToSign(gradeToSign);
	this->setGradeToExecute(gradeToExecute);
}

Form::Form(Form const& rhs) {
    *this = rhs;
}

Form& Form::operator=(Form const& rhs) {
	if (this != &rhs) {
		this->setName(rhs.getName());
		this->setSigned(rhs.getSigned());
		this->setGradeToSign(rhs.getGradeToSign());
		this->setGradeToExecute(rhs.getGradeToExecute());
	}
    return (*this);
}

Form::~Form() {
}

void        Form::setName(std::string name) {
	this->_name = name;
}

void        Form::setSigned( bool isSigned) {
	this->_isSigned = isSigned;
}

void        Form::setGradeToSign(int gradeToSign) {
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	else
		this->_gradeToSign = gradeToSign;
}

void        Form::setGradeToExecute(int gradeToExecute) {
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
		this->_gradeToExecute = gradeToExecute;
}

std::string	Form::getName(void) const {
	return (this->_name);
}

bool         Form::getSigned(void) const {
	return (this->_isSigned);
}

int         Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int         Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void        Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->setSigned(true);
}