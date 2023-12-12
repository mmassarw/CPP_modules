#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <climits>
# include <algorithm>
# include <vector>
# include <deque>
# include <cstdlib>

class PmergeMe {
	private:
        PmergeMe();
        PmergeMe(PmergeMe const&);

    public:
        PmergeMe& operator=(PmergeMe const&);
        ~PmergeMe();

		template <typename T, template <typename, typename> class Container>
		static void sortList(Container<T, std::allocator<T> > &list);

};

#endif // PMERGEME_HPP
