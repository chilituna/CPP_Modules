/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:22:02 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/24 12:10:00 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>
# include <iostream>
# include <cctype> // isprint, isdigit
# include <sstream>
# include <cstdlib> // atoi
# include <climits> // INT_MAX and INT_MIN
# include <cfloat>  // FLT_MAX, FLT_MIN (float), DBL_MAX, DBL_MIN (double)
# include <iomanip> // For setprecision and fixed

# define ASCII_PRINT_MIN 33
# define ASCII_PRINT_MAX 126
# define FLOAT_PRECISION 4
# define DOUBLE_PRECISION 4

class ScalarConverter
{
	public:
		//member functions
		static void convert(std::string literal);

	private:
		//orthodox canonical form
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();


};

#endif // SCALAR_CONVERTER_HPP