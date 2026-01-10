#pragma once
#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
		static void convert(std::string str);
};

struct scalarTypes
{
	char character;
	int number;
	float numberFloat;
	double numberDouble;
};

enum type
{
	CHAR,
	INTEGER,
	DOUBLE,
	FLOAT
};

