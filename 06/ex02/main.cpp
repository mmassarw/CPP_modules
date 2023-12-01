#include "Base.hpp"

Base* generateRandomInstance() {
    std::srand((unsigned int)(std::time(NULL)));
    int random = std::rand() % 3;

    switch (random) {
        case 0:
			std::cout << "A was generated" << std::endl;
            return new A();
        case 1:
			std::cout << "B was generated" << std::endl;
            return new B();
        case 2:
			std::cout << "C was generated" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
	std::cout << "Pointer: ";
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
	std::cout << "Reference: ";
    if (dynamic_cast<A*>(&p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(&p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(&p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

int main() {
    Base* instance = generateRandomInstance();

    identify(instance);
    identify(*instance);

    delete instance;
    return 0;
}
