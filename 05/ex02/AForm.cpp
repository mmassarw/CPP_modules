#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	this->setName(name);
	this->setGradeToSign(gradeToSign);
	this->setGradeToExecute(gradeToExecute);
}

AForm::AForm(AForm const& rhs) : _name(rhs.getName()), _isSigned(rhs.getSigned()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute()) {
}

AForm& AForm::operator=(AForm const& rhs) {
	if (this != &rhs) {
		this->setName(rhs.getName());
		this->setSigned(rhs.getSigned());
		this->setGradeToSign(rhs.getGradeToSign());
		this->setGradeToExecute(rhs.getGradeToExecute());
	}
    return (*this);
}

AForm::~AForm() {
}

void        AForm::setName(std::string name) {
	const_cast<std::string&>(this->_name) = name;
}

void        AForm::setSigned( bool isSigned) {
	this->_isSigned = isSigned;
}

void        AForm::setGradeToSign(int gradeToSign) {
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else
	const_cast<int&>(this->_gradeToSign) = gradeToSign;
}

void        AForm::setGradeToExecute(int gradeToExecute) {
	if (gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
		const_cast<int&>(this->_gradeToExecute) = gradeToExecute;
}

std::string	AForm::getName(void) const {
	return (this->_name);
}

bool         AForm::getSigned(void) const {
	return (this->_isSigned);
}

int         AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int         AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void        AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	this->setSigned(true);
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "The lowest grade is 150";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "The highest grade is 1";
}