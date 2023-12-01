template <typename T>
Array<T>::Array() : elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(size_t n) : _size(n) {
    this->elements = new T[n];
    for (size_t i = 0; i < n; ++i) {
        this->elements[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array &other) : elements(NULL), _size(0) {
    *this = other;
}

template <typename T>
Array<T>::~Array() {
    delete[] this->elements;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
    if (this != &rhs) {
        delete[] this->elements;
        this->_size = rhs._size;
        this->elements = new T[this->_size];
        for (size_t i = 0; i < this->_size; ++i) {
            this->elements[i] = rhs.elements[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index) const {
    if (index >= this->_size) {
        throw std::out_of_range("Array index out of bounds");
    }
    return this->elements[index];
}

template <typename T>
size_t Array<T>::size() const {
    return this->_size;
}