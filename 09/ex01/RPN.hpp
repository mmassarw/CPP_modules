#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

class RPN {
    public:
        RPN() {}
        RPN(RPN const&) {}
        RPN& operator=(RPN const&) { return *this; }
        ~RPN() {}

        static double	calculator(const std::string&);
};

#endif // RPN_HPP
