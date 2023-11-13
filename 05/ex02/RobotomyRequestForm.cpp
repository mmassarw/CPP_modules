#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default Robotomy", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm(name, 72, 45) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs) {
    *this = rhs;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    AForm::operator=(rhs);
    return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat & bureaucrat) {
    if (!this->getSigned()) 
        throw AForm::FormNotSigned();
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();

    std::cout << "**** DRILLING NOISE ****" << std::endl; 
    std::srand((unsigned int)(time(NULL)));
    if (std::rand() % 2)
        std::cout << bureaucrat.getName() << " has been robotomized successfully" << std::endl;
    else
        std::cout << bureaucrat.getName() << " robotomizing failed" << std::endl;
}
