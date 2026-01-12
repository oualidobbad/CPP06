#include "Serializer.hpp"

Serializer::Serializer(/* args */){
}

Serializer::~Serializer(){

}

Serializer& Serializer::operator=(Serializer& other){
	(void)other;
	return *this;
}

Serializer::Serializer(Serializer& other){
	(void)other;	
}


uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
