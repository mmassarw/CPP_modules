#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int         _grade;

        void        setName(std::string);
        void        setGrade(int);
    public:
        Bureaucrat();
        Bureaucrat(std::string, int);
        Bureaucrat(Bureaucrat const&);
        Bureaucrat& operator=(Bureaucrat const&);
        ~Bureaucrat();

        void        incrementGrade(void);
        void        decrementGrade(void);
        void        signForm(Form&) const;

        std::string getName(void) const;
        int         getGrade(void) const;


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