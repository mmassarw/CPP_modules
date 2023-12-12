#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm	*_makeShrubbery(const std::string&);
        AForm	*_makeRobotomy(const std::string&);
        AForm	*_makePresidential(const std::string&);

    public:
        Intern();
        ~Intern();
        Intern(const Intern&);
        Intern & operator=(const Intern&);

    	AForm * makeForm(const std::string&, const std::string&);
};

#endif