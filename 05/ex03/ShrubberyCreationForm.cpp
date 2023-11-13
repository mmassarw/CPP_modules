#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default Shrubbery", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm(name, 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs) {
    *this = rhs;
}

 ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    AForm::operator=(rhs);
    return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat & bureaucrat) {
    if (!this->getSigned()) 
        throw AForm::FormNotSigned();
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();

    std::ofstream   outFile;
    outFile.open((this->getName()+ "_shrubbery").c_str());
    if (!outFile.is_open()) {
        std::cout << "Error: Failed to open file" << std::endl;
        return ;
    }
    outFile << ASCIITREE << std::endl;
}
