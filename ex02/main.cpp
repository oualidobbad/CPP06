#include <iostream>
#include <typeinfo>
#include "header.hpp"

int main() {
	Base *b = new A();
    long i = 0;
    const std::type_info& ti1 = typeid(*b);      // Get type_info of a variable
    const std::type_info& ti2 = typeid(int);    // Get type_info of a type

    std::cout << "Type of i: " << ti1.name() << std::endl;
    std::cout << "Type of int: " << ti2.name() << std::endl;
}
