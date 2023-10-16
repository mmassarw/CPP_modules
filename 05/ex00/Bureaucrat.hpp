# include <iostream>
# include <string>

class Bureaucrat {
    private:
        int         _grade;
        std::string _name;

    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const&);
        Bureaucrat& operator=(Bureaucrat const&);
        Bureaucrat operator++(void);
        Bureaucrat operator++(int num);
        Bureaucrat operator--(void);
        Bureaucrat operator--(int num);
        ~Bureaucrat();

        std::string getName(void);
        int         getGrade(void);
        void        setName(std::string name);
        void        setGrade(int grade);
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &rhs);