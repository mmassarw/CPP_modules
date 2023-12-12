#ifndef SERIALZER_HPP
# define SERIALZER_HPP

# include "Data.hpp"
# include <iostream>
# include <stdint.h>

class Serializer {
    private:
        Serializer();
        Serializer(Serializer const&);

    public:
        Serializer& operator=(Serializer const&);
        ~Serializer();

        static uintptr_t serialize(Data* ptr) {
            return reinterpret_cast<uintptr_t>(ptr);
        }

        static Data* deserialize(uintptr_t raw) {
            return reinterpret_cast<Data*>(raw);
        }
};

#endif // SERIALZER_HPP
