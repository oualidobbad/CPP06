#include <iostream>
#include "Serializer.hpp"

int main() {
	Data *data = new Data();
	uintptr_t raw;
	Data *ptr_raw;

	data->a = 42;
	data->test = "hello world!";
	raw = Serializer::serialize(data);

	ptr_raw = (Data *)(raw);

	std::cout << "================== serialize ptr_raw of raw ==================" << std::endl;
	std::cout << "value of Data: " << raw << std::endl;
	std::cout << "ptr_raw->a: " << ptr_raw->a << std::endl;
	std::cout << "ptr_raw->test: " << ptr_raw->test << std::endl;
	std::cout << "==========================================================" << std::endl << std::endl;

	data = Serializer::deserialize(raw);

	std::cout << "=================== Deserialize =====================" << std::endl;
	std::cout << "Value of Data: " << (long unsigned int)data << std::endl;
	std::cout << "data->a: " << data->a << std::endl;
	std::cout << "data->test: " << data->test << std::endl;
	std::cout << "=====================================================" << std::endl << std::endl;

	std::cout << "================ comapare addresses ================" << std::endl;
	if ((long unsigned int)(data) == raw)
		std::cout << "data == raw" << std::endl;
	else
		std::cout << "data != raw" << std::endl;
	std::cout << "====================================================" << std::endl;
	delete data;
    return 0;
}


