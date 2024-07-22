/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:57:51 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/19 12:40:55 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main( void ) {
Fixed a; // Default constructor, a = 0;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); // Creates b with 10.1 -> as fixed point 10.1016
std::cout << a << std::endl; // a = 0
std::cout << ++a << std::endl; // pre-incriment a (0.00390625 fp format)
std::cout << a << std::endl; // a = 0.00390625
std::cout << a++ << std::endl; // post-increment a (show original value, then increment)
std::cout << a << std::endl; // a has incremented to 0.0078125
std::cout << b << std::endl; // b = 10.1016
std::cout << Fixed::max( a, b ) << std::endl; //return greater value (b)
return 0;
}