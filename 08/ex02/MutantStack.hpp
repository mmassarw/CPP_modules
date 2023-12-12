#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack<T>& other);
        MutantStack& operator=(const MutantStack<T>& other);
        virtual ~MutantStack();
    
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif // MUTANT_STACK_HPP