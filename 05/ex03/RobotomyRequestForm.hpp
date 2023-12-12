#ifndef ROBOTOMYREQUESTFORM_HPP 
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& name);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& rhs);
        RobotomyRequestForm & operator=(const RobotomyRequestForm& rhs);

        void execute(const Bureaucrat & executor) const;
};

#endif