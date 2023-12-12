#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string&);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm&);
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);

        void execute(const Bureaucrat & executor) const;
};

#endif