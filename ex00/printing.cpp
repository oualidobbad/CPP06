#include "ScalarConverter.hpp"

void printing_char(scalarTypes &scalar)
{
	if (std::isprint(scalar.character))
		std::cout << "char: '" << scalar.character << "'"<< std::endl;
	else if (scalar.number < -128 || scalar.number > 127)
		std::cout << "char: impossible"<< std::endl;
	else
		std::cout << "char: Non displayable"<< std::endl;
}

void format_nan_inf(std::string  &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		str = str.substr(0, str.length() - 1);
}


void print_inf_nan(std::string &str)
{
	format_nan_inf(str);
	std::cout << "char: impossible"  << std::endl;
	std::cout << "int: impossible"   << std::endl;
	std::cout << "float: " <<  str << "f"<< std::endl;
	std::cout << "double: " << str << std::endl;
}

void print(scalarTypes scalar, std::string &str)
{
	if (scalar.flag == PSEUDO_LITERAL)
	{
		print_inf_nan(str);
		return ;
	}
	if (scalar.flag == OUT_OF_RANE)
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
	std::cout << "int: " << scalar.number << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << scalar.numberFloat << "f"<< std::endl;
	std::cout << "double: " << scalar.numberDouble << std::endl;
}


