/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:28:22 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/19 12:04:20 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed(void) : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// The copy constructor is used to create a new object as a copy of an existing object.
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = src.getRawBits();
}

// The copy assignment operator is used to copy the contents from
// one existing object to another existing object.
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) // check for self-assignment
		this->fixedPointValue = src.getRawBits();
	return *this;
}

// Default destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}
