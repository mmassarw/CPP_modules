#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool        _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;

    void        setName( std::string );
    void        setGradeToSign( int );
    void        setGradeToExecute( int );
public:
    Form();
    Form(std::string , int, int);
    Form(const Form&);
    ~Form();

    Form &operator=(const Form&);

    void        setSigned( bool );

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
