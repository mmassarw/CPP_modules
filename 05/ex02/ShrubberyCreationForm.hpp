#ifndef SHRUBBERYCREATIONFORM_HPP 
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string&);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

        void execute(const Bureaucrat&) const;
};

# define ASCIITREE  "            .        +          .      .          .\n     .            _        .                    .\n  ,              /;-._,-.____        ,-----.__\n ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n                      ,    `./  \\:. `.   )==-'  .\n    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n.           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n              \\:  `  X` _| _,\\/'   .-'\n.               \":._:`\\____  /:'  /      .           .\n                    \\::.  :\\/:'  /              +\n   .                 `.:.  /:'  }      .\n           .           ):_(:;   \\           .\n                      /:. _/ ,  |\n                   . (|::.     ,`                  .\n     .                |::.    {\\\n                      |::.\\  \\ `.\n                      |:::(\\    |\n              O       |:::/{ }  |                  (o\n               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\ndew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~"

#endif