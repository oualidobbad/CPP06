#include "header.hpp"

Base* generate(void) {
    int choice = std::rand() % 3;
    
    switch (choice) {
        case 0:  return new A();
        case 1:  return new B();
        case 2:  return new C();
        default: return NULL;
    }
}
