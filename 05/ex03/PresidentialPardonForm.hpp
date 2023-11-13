#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& name);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& rhs);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

        void execute(const Bureaucrat & executor);
};

#endif