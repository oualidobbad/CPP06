#include <iostream>

struct Base1 {
	int a;
	int f;
	Base1() : a(512), f(990)
	{}
};

struct Base2 {
	int h;
	char b;
	char r;
	Base2() : b(40), h(333), r(100) {}
	
};

struct Mix : public Base1, public Base2 {
	int c;
	int x;

	Mix() : c(900)
	{}
};

int main()
{
	Mix *thing = new Mix();

	Base2 *other1 = reinterpret_cast<Base2 *>(thing);

	std::cout << "xhe value of b : " << other1->r << std::endl;
}























    // Data original;
    // original. id = 42;
    // original. name = "Test Data";

    // std::cout << "=== Original Data ===" << std::endl;
    // std::cout << "Address: " << &original << std::endl;
    // std::cout << "ID:       " << original. id << std::endl;
    // std:: cout << "Name:     " << original. name << std::endl;
    // std::cout << std:: endl;

    // // Serialize:  pointer -> uintptr_t
    // uintptr_t raw = Serializer:: serialize(&original);
    // std::cout << "=== Serialized ===" << std::endl;
    // std:: cout << "Raw value (uintptr_t): " << raw << std::endl;
    // std::cout << std::endl;

    // // Deserialize:  uintptr_t -> pointer
    // Data* deserialized = Serializer::deserialize(raw);
    
    // std::cout << "=== Deserialized Data ===" << std:: endl;
    // std::cout << "Address: " << deserialized << std:: endl;
    // std::cout << "ID:      " << deserialized->id << std::endl;
    // std::cout << "Name:    " << deserialized->name << std::endl;
    // std::cout << std::endl;

    // // Verify:  compare pointers
    // std:: cout << "=== Verification ===" << std:: endl;
    // if (deserialized == &original) {
    //     std::cout << "✅ SUCCESS: Pointers are equal!" << std:: endl;
    // } else {
    //     std::cout << "❌ FAILURE: Pointers are NOT equal!" << std:: endl;
    // }