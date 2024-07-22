/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:28:30 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/07 10:17:16 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& src); // Copy constructor
		Fixed& operator=(const Fixed& src); // Copy assignement operator
		~Fixed();

		int getRawBits() const; //  returns the raw value of the fixed-point value
		void setRawBits(int const raw); // sets the raw value of the fixed-point number

	private:
		int	fixedPointValue;
		static const int fractionalBits;
};

#endif