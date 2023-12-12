#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const&);
    public:
        ScalarConverter& operator=(ScalarConverter const&);
        ~ScalarConverter();

        static void convert(const std::string&);
};

#endif // SCALARCONVERTER_HPP
