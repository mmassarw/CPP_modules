#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>
# include <list>

class RPN {
    private:
        RPN();
        RPN(RPN const&);

    public:
        RPN& operator=(RPN const&);
        ~RPN();

        static double	calculator(const std::string&);
};

#endif // RPN_HPP
