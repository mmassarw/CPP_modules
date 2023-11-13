#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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

        void        incrementGrade(void);
        void        decrementGrade(void);

        std::string getName(void) const;
        int         getGrade(void) const;

        void        setName(std::string);
        void        setGrade(int);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("The maximum grade is 150"); }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("The minimum grade is 1"); }
        };
};

std::ostream &operator<<(std::ostream&, Bureaucrat const&);

#endif