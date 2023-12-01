#ifndef SERIALZER_HPP
# define SERIALZER_HPP

# include "Data.hpp"
# include <iostream>
# include <stdint.h>

class Serializer {
    public:
        Serializer() {}
        Serializer(Serializer const&) {}
        Serializer& operator=(Serializer const&) { return *this; }
        ~Serializer() {}

        static uintptr_t serialize(Data* ptr) {
            return reinterpret_cast<uintptr_t>(ptr);
        }

        static Data* deserialize(uintptr_t raw) {
            return reinterpret_cast<Data*>(raw);
        }
};

#endif // SERIALZER_HPP
