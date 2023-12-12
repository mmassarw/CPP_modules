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

    void            setName( std::string );
    void            setGradeToSign( int );
    void            setGradeToExecute( int );
public:
    AForm();
    AForm(std::string , int, int);
    AForm(const AForm&);
    virtual ~AForm();

    AForm &operator=(const AForm&);

    void            setSigned( bool );

    std::string     getName() const;
    bool            getSigned() const;
    int             getGradeToSign() const;
    int             getGradeToExecute() const;

    void            beSigned(const Bureaucrat&);
    virtual void    execute(const Bureaucrat&) const = 0;

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

    class FormNotSigned : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif
