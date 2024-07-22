/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:57:56 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/19 12:35:15 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed(void) : fixedPointValue(0) {}

// Constructor int to fixed-point value
Fixed::Fixed(const int integer) : fixedPointValue(integer << fractionalBits) {}

// Constructor float to  fixed-point value
Fixed::Fixed(const float floatingPoint) : fixedPointValue(roundf(floatingPoint * (1 << fractionalBits))) {}

// Copy constructor
Fixed::Fixed(const Fixed &src) : fixedPointValue(src.getRawBits()) {}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->fixedPointValue = src.getRawBits();
	return *this;
}

// Default destructor
Fixed::~Fixed(void) {}


// Getter and setter
int Fixed::getRawBits(void) const
{
	return(this->fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
}


// Convertions for fixed-point value
int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}
float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}


// Operator overloading

// Comparison operators
bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixedPointValue > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const
{
	return (this->fixedPointValue < other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fixedPointValue >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fixedPointValue <= other.getRawBits());
}
bool Fixed::operator==(const Fixed& other) const
{
	return (this->fixedPointValue == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const
{
	return (this->fixedPointValue != other.getRawBits());
}

// Arithmetic operators:
// use float to ensure precision:
Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment and decrement operators
// Pre:
Fixed& Fixed::operator++()
{
	this->fixedPointValue++;
	return *this;
}
Fixed& Fixed::operator--()
{
	this->fixedPointValue--;
	return *this;
}
// Post:
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->fixedPointValue++;
	return tmp;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->fixedPointValue--;
	return tmp;
}

// Static member functions
// Static functions can be called directly on the class itself, without needing an instance of the class.
// Static functions do not have access to "this" pointer because they are not associated with any particular object instance.
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}