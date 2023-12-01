#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <cstdlib>
# include <exception>

template <typename T>
class Array {
	private:
	    T *elements;
	    size_t	_size;

	public:
	    Array();
	    Array(size_t);
	    Array(const Array&);
	    Array &operator=(const Array&);
	    ~Array();

	    T &operator[](size_t) const;

	    size_t	size() const;
};

# include "Array.tpp"

#endif // ARRAY_HPP
