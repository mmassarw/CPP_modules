#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default Pardon", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs) {
    *this = rhs;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    AForm::operator=(rhs);
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat & bureaucrat) {
    if (!this->getSigned()) 
        throw AForm::FormNotSigned();
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();

    std::cout << bureaucrat.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
