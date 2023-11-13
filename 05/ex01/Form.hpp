#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string _name;
    bool        _isSigned;
    int         _gradeToSign;
    int         _gradeToExecute;

public:
    Form();
    Form(std::string , int, int);
    Form(const Form&);
    ~Form();

    Form &operator=(const Form&);

    void        setName( std::string );
    void        setSigned( bool );
    void        setGradeToSign( int );
    void        setGradeToExecute( int );

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned(const Bureaucrat&);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return ("Grade too high"); }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw() { return ("Grade too low"); }
    };
};

#endif
