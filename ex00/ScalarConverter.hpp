#pragma once
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>
#include <iomanip>
#include <limits.h>


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
	int flag;
};

enum type
{
	CHAR,
	INTEGER,
	DOUBLE,
	FLOAT,
	OTHER,
	PSEUDO_LITERAL,
	OUT_OF_RANE,
	OVERFLOW_DBL,
	OVERFLOW_FLT,
};



type getTypeOfString(std::string str);
void converter(std::string str, scalarTypes &scalar, type typ);
void print(scalarTypes scalar, std::string &str);
void print_inf_nan(std::string &str);