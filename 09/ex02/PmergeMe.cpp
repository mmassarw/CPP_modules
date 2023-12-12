#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const&) {}

PmergeMe& PmergeMe::operator=(PmergeMe const&) { return *this; }

PmergeMe::~PmergeMe() {}

template <typename T>
static void sortPair(T &a, T &b) {
    if (a > b) std::swap(a, b);
}

template <typename T>
static void recursiveSortPairs(T &pairs, int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    recursiveSortPairs(pairs, start, mid);
    recursiveSortPairs(pairs, mid + 1, end);

    T temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (pairs[i].first < pairs[j].first) temp.push_back(pairs[i++]);
        else temp.push_back(pairs[j++]);
    }
    while (i <= mid) temp.push_back(pairs[i++]);
    while (j <= end) temp.push_back(pairs[j++]);

    for (int k = start; k <= end; k++) pairs[k] = temp[k - start];
}

template <typename T>
static void binarySearchInsert(T &mainChain, typename T::value_type value) {
    typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    mainChain.insert(it, value);
}

template <typename T, template <typename, typename> class Container>
void sortList(Container<T, std::allocator<T> > &list) {
    Container<std::pair<T, T>, std::allocator<std::pair<T, T> > > pairs;
    for (size_t i = 0; i + 1 < list.size(); i += 2) {
        sortPair(list[i], list[i + 1]);
        pairs.push_back(std::make_pair(list[i], list[i + 1]));
    }
    if (list.size() % 2 != 0) {
        pairs.push_back(std::make_pair(list.back(), list.back()));
    }

    recursiveSortPairs(pairs, 0, pairs.size() - 1);

    Container<T, std::allocator<T> > mainChain, bElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        if (pairs[i].first != pairs[i].second) {
            bElements.push_back(pairs[i].second);
        }
    }

    for (typename Container<T, std::allocator<T> >::iterator it = bElements.begin(); it != bElements.end(); ++it) {
        binarySearchInsert(mainChain, *it);
    }

    list = mainChain;
}