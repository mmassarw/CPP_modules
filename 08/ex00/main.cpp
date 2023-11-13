#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number to find>" << std::endl;
        return 1;
    }

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(int);

    std::vector<int> vector(array, array + size);
    std::list<int> list(array, array + size);

    int needle = std::atoi(argv[1]);

    // Test with vector
    std::vector<int>::iterator itVector = easyfind(vector, needle);
    if (itVector != vector.end()) {
        std::cout << "Found " << needle << " in vector at position " << std::endl;
    } else {
        std::cout << needle << " not found in vector" << std::endl;
    }

    // Test with list
    std::list<int>::iterator itList = easyfind(list, needle);
    if (itList != list.end()) {
        std::cout << "Found " << needle << " in list" << std::endl;
    } else {
        std::cout << needle << " not found in list" << std::endl;
    }

    return 0;
}
