#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
    public:
        ScalarConverter() {}
        ScalarConverter(ScalarConverter const&) {}
        ScalarConverter& operator=(ScalarConverter const&) { return *this; }
        ~ScalarConverter() {}

        static void convert(const std::string&);
};

#endif // SCALARCONVERTER_HPP
