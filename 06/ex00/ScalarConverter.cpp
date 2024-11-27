/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:57:33 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/27 15:26:42 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// HELPER FUNCTIONS

//  --- 1. detect the type of the literal passed as parameter---


// CHAR
// - char literal should have exactly one character
// - non displayable characters shouldn’t be used as inputs
bool isChar(const std::string& str)
{
	return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

// INT
// - Create string stream and try extracting an integer and check if extraction succeeded
// - std::stringstream automatically stops parsing when it encounters a non-numeric character:
// -- Ensure ss.eof() to verify no trailing characters exist
// - use long long to check edge values
bool isInt(const std::string& str)
{
	std::stringstream ss(str);
	long long value;

	ss >> value;

	return !ss.fail() && ss.eof() && value <= INT_MAX && value >= INT_MIN;
}

// FLOAT
// - check for pseudo-liternals
// - otherwise must end with f
// - remove f and try to extrat float using string stream
bool isFloat(const std::string& str)
{
	if (str == "-inff" || str == "+inff" || str == "inff")
		return true;
	if (str[str.length() - 1] != 'f')
		return false;

	std::string base = str.substr(0, str.length() -1);
	std::stringstream ss(base);
	double value;

	ss >> value;

	return !ss.fail() && ss.eof() && value <= FLT_MAX && value >= -FLT_MAX;
}

// DOUBLE
// - check for pseudo-liternals
// - use the same string stream method as for int and float
bool isDouble(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf" || str == "NaN")
		return true;

	std::stringstream ss(str);
	long double value;

	ss>>value;

	return !ss.fail() && ss.eof() && value <= DBL_MAX && value >= -DBL_MAX;
}

// PSEUDO-LITERALS
bool isPseudo(const std::string& str)
{
	return str == "nan" || str == "+inf" || str == "-inf" || str == "-inff" || str == "+inff"
		|| str == "NaN" || str == "inf" || str == "inff";
}


// --- 2. convert it from string to its actual type ---
// --- then convert it explicitly to the three other data types ---
// --- display the results ---

// If a conversion does not make any sense or overflows, display a message to inform
// the user that the type conversion is impossible.

void handleChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<float>(c)  << ".0" << std::endl;
}

void handleInt(int i)
{
	if ( i <  0 || i > 255)
		std::cout << "char: Impossible" << std::endl;
	else if (i < ASCII_PRINT_MIN || i > ASCII_PRINT_MAX)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i)  << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<float>(i)  << ".0" << std::endl;
}

void handleFloat(float f)
{
	if ( f <  0 || f > 255)
		std::cout << "char: Impossible" << std::endl;
	else if (f < ASCII_PRINT_MIN || f > ASCII_PRINT_MAX)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " <<  std::fixed << std::setprecision(FLOAT_PRECISION) <<  f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(DOUBLE_PRECISION) << static_cast<float>(f) << std::endl;
}

void handleFloatPseudo(std::string literal)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " <<  literal << std::endl;
	std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
}

void handleDouble(double d)
{
	if ( d <  0 || d > 255)
		std::cout << "char: Impossible" << std::endl;
	else if (d < ASCII_PRINT_MIN || d > ASCII_PRINT_MAX)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(FLOAT_PRECISION) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(DOUBLE_PRECISION) << d << std::endl;
}

void handleDoublePseudo(std::string literal)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
}


// custom stof and stod as they are not included in std c++98

float	my_stof(const std::string& str)
{
	std::string base = str.substr(0, str.length() -1);
	std::stringstream ss(base);
	float value;

	ss >> value;

	return value;
}

double	my_stod(const std::string& str)
{
	std::stringstream ss(str);
	double value;

	ss >> value;

	return value;
}


// MEMBER FUNCTIONS

void ScalarConverter::convert(std::string literal)
{
	if (literal == "")
		throw "Error: string literal cannot be empty.";
	if (isChar(literal))
		handleChar(literal[0]);
	else if (isInt(literal))
		handleInt(atoi(literal.c_str()));
	else if (isFloat(literal))
	{
		if (isPseudo(literal))
			handleFloatPseudo(literal);
		else
			handleFloat(my_stof(literal));
	}
	else if (isDouble(literal))
	{
		if (isPseudo(literal))
			handleDoublePseudo(literal);
		else
			handleDouble(my_stod(literal));
	}
	else
		throw "Error: Type not recognized.";
}










