#include <iostream>
#include <typeinfo>
#include "header.hpp"

int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
}

