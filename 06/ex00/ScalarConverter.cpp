#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const&) {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const&) { return *this; }

ScalarConverter::~ScalarConverter() {}

static bool isValidNumber(const std::string& literal) {
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return true;

    if (literal == "+inff" || literal == "-inff" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "nan")
        return true;
    
    std::string validate = literal;

    if (literal[literal.length() - 1] == 'f')
        validate = literal.substr(0, literal.length() - 1);

    if (validate.empty() || validate[validate.length() - 1] == '.') {
        return false;
    }

    bool hasDecimalPoint = false;
    size_t start = (validate[0] == '+' || validate[0] == '-') ? 1 : 0;

    for (size_t i = start; i < validate.length(); ++i) {
        if (validate[i] == '.') {
            if (hasDecimalPoint) return false;
            hasDecimalPoint = true;
        } else if (!std::isdigit(validate[i])) {
            return false;
        }
    }

    return true;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: 0" << std::endl;
        std::cout << "float: 0.0f" << std::endl;
        std::cout << "double: 0.0" << std::endl;
    }
    if (!isValidNumber(literal)) {
        std::cout << "invalid input" << std::endl;
        return ;
    }
    
    double value;

    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        value = static_cast<double>(static_cast<unsigned char>(literal[0]));
    else
        value = atof(literal.c_str());

    // Handle conversion to char
    if (std::isnan(value) || value > std::numeric_limits<char>::max() ||
        value < std::numeric_limits<char>::min()) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char ch = static_cast<char>(value);
        if (std::isprint(ch)) {
            std::cout << "char: '" << ch << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }

    // Handle conversion to int
    if (std::isnan(value) || std::isinf(value) ||
        value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
    std::cout << "double: " << value << std::endl;
}