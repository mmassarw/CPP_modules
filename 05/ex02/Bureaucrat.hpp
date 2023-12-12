#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        std::string _name;
        int         _grade;

        void        setName(std::string);
    public:
        Bureaucrat();
        Bureaucrat(std::string, int);
        Bureaucrat(Bureaucrat const&);
        Bureaucrat& operator=(Bureaucrat const&);
        ~Bureaucrat();

        void        incrementGrade(void);
        void        decrementGrade(void);
        void        signForm(AForm&) const;
        void        executeForm(AForm&) const;

        std::string getName(void) const;
        int         getGrade(void) const;

        void        setGrade(int);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream&, Bureaucrat const&);

#endif