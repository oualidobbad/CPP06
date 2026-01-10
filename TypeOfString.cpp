#include "ScalarConverter.hpp"

bool isFloat(std::string str)
{
	if (str[str.length() - 1] != 'f')
		return false;
	for (int i = 0; str.length() > i; i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return false;
	}
	return true;
}

bool isInt(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
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
	for (int i  = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return false;
	}
	return true;
}

type getTypeOfString(std::string str)
{
	if (isInt(str))
		return INTEGER;
	else if (isFloat(str))
		return FLOAT;
	else if (is)
}
