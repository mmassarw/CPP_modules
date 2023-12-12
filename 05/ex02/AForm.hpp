#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string _name;
    bool        _isSigned;
    int         _gradeToSign;
    int         _gradeToExecute;

public:
    AForm();
    AForm(std::string , int, int);
    AForm(const AForm&);
    virtual ~AForm();

    AForm &operator=(const AForm&);

    void            setName( std::string );
    void            setSigned( bool );
    void            setGradeToSign( int );
    void            setGradeToExecute( int );

    std::string     getName() const;
    bool            getSigned() const;
    int             getGradeToSign() const;
    int             getGradeToExecute() const;

    void            beSigned(const Bureaucrat&);
    virtual void    execute(const Bureaucrat&) const = 0;

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

    class FormNotSigned : public std::exception
    {
    public:
        virtual const char* what() const throw() { return ("Form not signed"); }
    };
};

#endif
