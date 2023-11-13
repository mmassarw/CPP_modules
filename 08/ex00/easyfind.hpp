#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T& haystack, int needle) {
	typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
	return it;
}

#endif