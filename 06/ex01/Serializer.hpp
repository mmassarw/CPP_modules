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

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif // SERIALZER_HPP
