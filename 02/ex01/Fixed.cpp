/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:14:10 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/19 12:22:38 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed(void) : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
// Constructor that converts the int given as parameter to corresponding fixed-point value:
// takes an integer and shifts it left by the number of fractional bits.
// This allows the integer to be represented in a format suitable for fixed-point arithmetic.
Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = integer << fractionalBits;
}
// Constructor that converts the float given as parameter to corresponding fixed-point value
// takes a float and multiplies it by 2^fractional_bits, converting it to a fixed-point representation.
// The roundf function is used to round the result to the nearest integer.
Fixed::Fixed(const float floatingPoint)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(floatingPoint * (1 << fractionalBits));
}
// Copy constructor
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixedPointValue = src.getRawBits();
	return *this;
}
// Default destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Getter and setter
int Fixed::getRawBits(void) const
{
	return(this->fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
}

// Convert fixed-point value to int
int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> fractionalBits);
}

// Convert fixed-point value to float
float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << fractionalBits));
}

// Overloading the stream insertion operator <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
