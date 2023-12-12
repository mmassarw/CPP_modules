#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const&) {}

RPN& RPN::operator=(RPN const&) {
    return *this;
}

RPN::~RPN() {}

double RPN::calculator(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
		if (token.length() > 1 && token != "+" && token != "-" && token != "*" && token != "/") {
            throw std::runtime_error("Invalid token size: " + token);
        }
        if (isdigit(token[0])) {
            stack.push(atoi(token.c_str()));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Insufficient operands for the operation.");
            }

            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();

            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    throw std::runtime_error("Division by zero.");
                }
                stack.push(a / b);
            }
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("The RPN expression is not valid.");
    }

    return stack.top();
}