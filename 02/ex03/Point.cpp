/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:26:26 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/15 16:31:02 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()) {}

Point::~Point(void) {}

Point& Point::operator=(const Point &src)
{
	// Since x and y are const, we cannot assign them new values
    // We don't need to do anything here because x and y are already initialized
	(void)src;
    return *this;
}

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}


