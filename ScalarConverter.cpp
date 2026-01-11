#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter::~ScalarConverter(){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

void ScalarConverter::convert(std::string str)
{
	scalarTypes  scalar;
	type typ;

	scalar.character = 0;
	scalar.number = 0;
	scalar.numberDouble = 0.0;
	scalar.numberFloat = 0.f;
	scalar.flag = 0;

	typ = getTypeOfString(str);
	converter(str, scalar, typ);
	print(scalar);
}