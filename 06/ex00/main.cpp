/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:45:08 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/27 13:43:16 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Incorrect input. Please give ./scalar <literal>\n";
		return 1;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const char* str)
	{
		std::cerr << str << std::endl;
	}

	return 0;
}

// // INPUT TO TEST:
// - 0
// - nan
// - NaN
// - inf
// - inff
// - -inf
// - -inff
// - +inf
// - +inff
// - 42.0f
// - 2147483647
// - 2147483648
// - -2147483648
// - -2147483649
// - 1.0e40 (bigger than max float)
// - max float: 3.40282e+38
// - max fouble: 1.79769e+308

