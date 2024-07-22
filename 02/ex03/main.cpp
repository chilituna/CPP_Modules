/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:57:51 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/15 17:10:51 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 5);
    Point inside(2.4, 2.8);
    Point outside(2, -2);
	Point edge(0, 2.5);

	if (bsp(a, b, c, inside))
		std::cout << "--> Point is inside" << std::endl;
	else
		std::cout << "--> Point is outside" << std::endl;

	if (bsp(a, b, c, outside))
		std::cout << "--> Point is inside" << std::endl;
	else
		std::cout << "--> Point is outside" << std::endl;
		
	if (bsp(a, b, c, edge))
		std::cout << "--> Point is inside" << std::endl;
	else
		std::cout << "--> Point is outside" << std::endl;

    return 0;
}
