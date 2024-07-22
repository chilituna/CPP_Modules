/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:57:53 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/19 12:41:32 by aarponen         ###   ########.fr       */
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
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		Fixed(const Fixed& src);
		~Fixed();

		Fixed& operator=(const Fixed& src);

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;

		//Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		// Arithmentic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		// Increment/Decrement operators
		Fixed& operator++(); // Pre-increment
		Fixed& operator--(); // Pre-decrement
		Fixed operator++(int); // Post-increment
		Fixed operator--(int); // Post-increment
		// Static member functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	private:
		int	fixedPointValue;
		static const int fractionalBits;
};

// overload of the insertion (<<) operator outputs the floating-point representation of a Fixed object to the provided output stream.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif
