#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>


class Bureaucrat {
    private:
        std::string _name;
        int         _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string, int);
        Bureaucrat(Bureaucrat const&);
        Bureaucrat& operator=(Bureaucrat const&);
        ~Bureaucrat();

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

        void        incrementGrade(void);
        void        decrementGrade(void);

        std::string getName(void) const;
        int         getGrade(void) const;
        void        setName(std::string);
        void        setGrade(int);
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &rhs);

#endif