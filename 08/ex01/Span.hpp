#ifndef SPAN_HPP
#define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits>

class Span {
private:
    std::vector<int> numbers;
    size_t maxSize;

public:
    Span();
    Span(size_t);
    Span(const Span&);
    Span& operator=(const Span&);
    ~Span();

    void	addNumber(int);
    int		shortestSpan();
    int		longestSpan();
};

#endif // SPAN_HPP
