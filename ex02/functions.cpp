#include "header.hpp"

Base* generate(void) {
	std::srand(static_cast<unsigned int>(time(NULL)));
    int choice = std::rand() % 3;
    
    switch (choice) {
        case 0:  return new A();
        case 1:  return new B();
        case 2:  return new C();
        default: return NULL;
    }
}

bool isA(Base* p) { 
	return dynamic_cast<A*>(p) != NULL;
}

bool isB(Base* p) { 
	return dynamic_cast<B*>(p) != NULL;
}

bool isC(Base* p) { 
	return dynamic_cast<C*>(p) != NULL; 
}

void identify(Base* p) {

    bool (*func[3])(Base *p) = {&isA, &isB, &isC};
    std::string names[3] = { "A", "B", "C" };

    for (int i = 0; i < 3; i++) {
        if (func[i](p)) {
            std::cout << names[i] << std::endl;
            return;
        }
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
	catch (...) {
		try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
		} 
		catch (...) {
			try {
			dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
			return;
			} 
			catch (...) {}
		}
	}
}

#define TRY_CAST(Type) \
try { \
(void)dynamic_cast<Type&>(p); \
std::cout << #Type << std::endl; \
return; \
} catch (...) {}

