/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:50:00 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/07 10:52:21 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits.h>

class Fixed
{
	public:
		Fixed();
		Fixed(const int integer); // constructor that converts the int given as parameter to corresponding fixed-point value
		Fixed(const float floatingPoint); // constructor that converts the float given as parameter to corresponding fixed-point value
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& src);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const; // converts fixed-point value to float
		int toInt() const; // converts fixed-point value to int

	private:
		int	fixedPointValue;
		static const int fractionalBits;
};

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif