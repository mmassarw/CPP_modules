#include "Intern.hpp"

Intern::Intern(void) {
}

Intern::~Intern(void) {
}

Intern::Intern(const Intern& rhs) {
    *this = rhs;
}

Intern	&Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return (*this);
}

AForm	*Intern::_makeShrubbery(const std::string &name) {
    return (new ShrubberyCreationForm(name));
}

AForm	*Intern::_makeRobotomy(const std::string &name) {
    return (new RobotomyRequestForm(name));
}

AForm	*Intern::_makePresidential(const std::string &name) {
    return (new PresidentialPardonForm(name));
}

AForm	*Intern::makeForm(const std::string &formType, const std::string &name) {
    std::string formTypes[3] = {"shrubbery creation",
                "robotomy request", "presidential pardon"};

    AForm	*(Intern::*f[3])(const std::string & tar) = {&Intern::_makeShrubbery,
                &Intern::_makeRobotomy, &Intern::_makePresidential};

    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == formType) {
            std::cout << "Intern creates " << formType << std::endl;
            return (this->*f[i])(name);
        }
    }
    std::cout << "Intern couldn't find form " << formType << std::endl;
    return (NULL);
}