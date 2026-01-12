#include "ScalarConverter.hpp"

bool isFloat(std::string str)
{
	if (str[str.length() - 1] != 'f')
		return false;
	for (long unsigned int i = 0; str.length() > i; i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return false;
	}
	return true;
}

bool isInt(std::string str)
{
	for (long unsigned int i = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isChar(std::string str)
{
	if (str.length() > 1)
		return false;
	if (std::isalpha(str[0]))
		return true;
	else
		return false;
}

bool isDouble(std::string str)
{
	for (long unsigned int i  = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (!std::isdigit(str[i]) && str[i] != '.')
			return false;
	}
	return true;
}

bool isPseudoLiteral(std::string &str)
{
	if (str == "-inf" || str == "+inf")
		return true;
	if (str == "+inff" || str == "-inff")
		return true;
	if (str == "nan" || str == "nanf")
		return true;
	return false;
}

type getTypeOfString(std::string str)
{
	if (isInt(str))
		return INTEGER;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	else if (isChar(str))
		return CHAR;
	else if (isPseudoLiteral(str))
		return PSEUDO_LITERAL;
	else
		return OTHER;
}
