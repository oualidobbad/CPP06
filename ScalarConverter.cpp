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
	scalarTypes  type;

	if (std::isdigit(str[0]))
	{
		for (int i  = 0; i < str.length(); i++)
		{
			if ()
		}
	}
	else if ()
}