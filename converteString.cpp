#include "ScalarConverter.hpp"

void convertToInt(std::string str, scalarTypes &scalar)
{
	errno = 0;
    long temp = strtol(str.c_str(), NULL, 0);
	
	if (errno || temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
		scalar.flag = OVERFLOW;
    scalar.number = static_cast<int>(temp);
    if (scalar.number <= 127 && scalar.number >= -128)
        scalar.character = static_cast<char>(scalar.number);
    scalar.numberFloat = static_cast<float>(scalar.number);
    scalar.numberDouble = static_cast<double>(scalar.number);
}

void convertToFloat(std::string str, scalarTypes &scalar)
{
	std::cout << "here\n";
	double tmp = strtod(str.c_str(),NULL);
	if (tmp == +INFINITY || tmp == -INFINITY)
		scalar.flag = OVERFLOW_FLT;
	if (tmp < INT_MIN || tmp > INT_MAX)
		scalar.flag = OVERFLOW_FLT;
    scalar.numberFloat = static_cast<float>(tmp);
    scalar.number = static_cast<int>(scalar.numberFloat);
    scalar.numberDouble = static_cast<double>(scalar.numberFloat);
    if (scalar.numberFloat <= 127 && scalar.numberFloat >= -128)
        scalar.character = static_cast<char>(scalar.numberFloat);
}

void convertToDouble(std::string str, scalarTypes &scalar)
{
    scalar.numberDouble = strtod(str.c_str(), NULL);
	if (scalar.numberDouble == +INFINITY || scalar.numberDouble == -INFINITY)
		scalar.flag = OVERFLOW_DBL;
    scalar.number = static_cast<int>(scalar.numberDouble);
    scalar.numberFloat = static_cast<float>(scalar.numberDouble); 
    if (scalar.numberDouble <= 127 && scalar.numberDouble >= -128)
        scalar.character = static_cast<char>(scalar.numberDouble);
}

void convertToChar(std::string str, scalarTypes &scalar)
{
    scalar.character = str[0];
    scalar.number = static_cast<int>(scalar.character);
    scalar.numberDouble = static_cast<double>(scalar.character);
    scalar.numberFloat = static_cast<float>(scalar.character);
}

void converter(std::string str, scalarTypes &scalar, type typ)
{
	switch (typ)
	{
		case INTEGER:
			convertToInt(str, scalar);
			break;
		case FLOAT:
			convertToFloat(str, scalar);
			break;
		case DOUBLE:
			convertToDouble(str, scalar);
			break;
		case CHAR:
			convertToChar(str, scalar);
			break;
		default:
			break;
	}

}