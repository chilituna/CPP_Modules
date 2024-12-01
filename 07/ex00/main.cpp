/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:57:08 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/01 12:13:24 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int main( void )
{
	std::cout << std::endl;

	std::cout <<  " --- BASIC TEST WITH INT ---" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::cout <<  " --- BASIC TEST WITH STRING ---" << std::endl;
	std::string c = "alise";
	std::string d = "arponen";
	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "Aftr swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;

	std::cout <<  " --- TEST WITH SAME VALUE MIN---" << std::endl;
	a = 42;
	b = 42;
	int& result = ::min(a, b);
	std::cout << "Address of a: " << &a << std::endl;
	std::cout << "Address of b: " << &b << std::endl;
	std::cout << "Address of result(min): " << &result << std::endl;
	if (&result == &a)
	{
		std::cout << "Returned: a" << std::endl;
    }
	else if (&result == &b)
	{
        std::cout << "Returned: b" << std::endl;
	}
	std::cout << std::endl;

		std::cout <<  " --- TEST WITH SAME VALUE MAX---" << std::endl;
	result = ::max(a, b);
	std::cout << "Address of a: " << &a << std::endl;
	std::cout << "Address of b: " << &b << std::endl;
	std::cout << "Address of result(max): " << &result << std::endl;
	if (&result == &a)
	{
		std::cout << "Returned: a" << std::endl;
    }
	else if (&result == &b)
	{
        std::cout << "Returned: b" << std::endl;
	}

	return 0;
}