#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : maxSize(0) {}

Span::Span(size_t N) : maxSize(N) {}

Span::Span(const Span& rhs) : numbers(rhs.numbers), maxSize(rhs.maxSize) {}

Span& Span::operator=(const Span& rhs) {
    if (this != &rhs) {
        this->numbers = rhs.numbers;
        this->maxSize = rhs.maxSize;
    }
    return *this;
}

Span::~Span() {}

// Member functions
void Span::addNumber(int number) {
    if (this->numbers.size() >= this->maxSize) {
        throw std::length_error("Span is already full.");
    }
    this->numbers.push_back(number);
}

size_t Span::shortestSpan() {
    if (this->numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    size_t span;
    std::sort(this->numbers.begin(), this->numbers.end());
    size_t shortest = std::numeric_limits<size_t>::max();
    for (size_t i = 0; i < this->numbers.size() - 1; ++i) {
        if (this->numbers[i + 1] > this->numbers[i])
            span = static_cast<size_t>(this->numbers[i + 1]) - static_cast<size_t>(this->numbers[i]);
        else
            span = static_cast<size_t>(this->numbers[i]) - static_cast<size_t>(this->numbers[i + 1]);
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

size_t Span::longestSpan() {
    if (this->numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    int min = *std::min_element(this->numbers.begin(), this->numbers.end());
    int max = *std::max_element(this->numbers.begin(), this->numbers.end());
    return static_cast<size_t>(max) - static_cast<size_t>(min);
}
