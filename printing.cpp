#include "ScalarConverter.hpp"


void printing_type_int(scalarTypes &scalar)
{
	std::cout << "int: " << scalar.number << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << scalar.numberFloat << "f"<< std::endl;
	std::cout << "double: " << scalar.numberDouble << std::endl;
}

void printing_char(scalarTypes &scalar)
{
	if (std::isprint(scalar.character))
		std::cout << "char: '" << scalar.character << "'"<< std::endl;
	else if (scalar.number < -128 || scalar.number > 127)
		std::cout << "char: impossible"<< std::endl;
	else
		std::cout << "char: Non displayable"<< std::endl;
}

void print(scalarTypes scalar)
{
	if (scalar.flag == OVERFLOW)
	{
		std::cout << "char: impossible"  << std::endl;
		std::cout << "int: impossible"   << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible"<< std::endl;
		return;
	}
	if (scalar.flag == OVERFLOW_DBL || scalar.flag == OVERFLOW_FLT)
	{
		std::cout << "char: impossible"  << std::endl;
		std::cout << "int: impossible"   << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << scalar.numberFloat << "f"<< std::endl;
		std::cout << "double: " << scalar.numberDouble << std::endl;
		return;
	}

	printing_char(scalar);
	printing_type_int(scalar);
}

