#include "PmergeMe.hpp"

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
    PmergeMe::sortList<int, std::vector>(vectorList);
    end = clock();
    double  elapsedVector = (double(end - start) / CLOCKS_PER_SEC) * 1000000;

    start = clock();
    PmergeMe::sortList<int, std::deque>(dequeList);
    end = clock();
    double  elapsedDeque = (double(end - start) / CLOCKS_PER_SEC) * 1000000;

    std::cout << "After: ";
    printContainer(dequeList);
    std::cout << "Time to process a range of 5 elements with std::vector : " << elapsedVector << " us" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::deque : " << elapsedDeque << " us" << std::endl;

    return 0;
}