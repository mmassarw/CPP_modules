#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstdlib>

std::pair<std::vector<int>, std::deque<int> > processInputs(int ac, char **av) {
    std::vector<int> vectorList;
    std::deque<int> dequeList;

    for (int i = 1; i < ac; i++) {
        char* end;
        long num = std::strtol(av[i], &end, 10);

        if (end == av[i] || *end != '\0') {
            throw std::runtime_error("Invalid input, not a valid integer");
        }
        if (num < 0) {
            throw std::runtime_error("Negative numbers are not allowed");
        }
        if (std::find(vectorList.begin(), vectorList.end(), num) != vectorList.end()) {
            throw std::runtime_error("Repeating numbers are not allowed");
        }
        if (num > INT_MAX) {
            throw std::runtime_error("Number is out of bounds");
        }

        vectorList.push_back(static_cast<int>(num));
        dequeList.push_back(static_cast<int>(num));
    }

    return std::make_pair(vectorList, dequeList);
}

template <typename T>
void    printContainer(T list) {
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void sortPair(T &a, T &b) {
    if (a > b) std::swap(a, b);
}

template <typename T>
void recursiveSortPairs(T &pairs, int start, int end) {
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
void binarySearchInsert(T &mainChain, typename T::value_type value) {
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

int main(int ac, char **av) {
    std::vector<int> vectorList;
    std::deque<int> dequeList;
    clock_t             start;
    clock_t             end;

	if (ac <= 1)
        std::cout << "Usage: ./PmergeMe `set of numbers'" << std::endl;
		return 1;
    try {
        std::pair<std::vector<int>, std::deque<int> > result = processInputs(ac, av);
        vectorList = result.first;
        dequeList = result.second;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    printContainer(vectorList);

    start = clock();
    sortList<int, std::vector>(vectorList);
    end = clock();
    double  elapsedVector = (double(end - start) / CLOCKS_PER_SEC) * 1000000;

    start = clock();
    sortList<int, std::deque>(dequeList);
    end = clock();
    double  elapsedDeque = (double(end - start) / CLOCKS_PER_SEC) * 1000000;

    std::cout << "After: ";
    printContainer(dequeList);
    std::cout << "Time to process a range of 5 elements with std::vector : " << elapsedVector << " us" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::deque : " << elapsedDeque << " us" << std::endl;

    return 0;
}