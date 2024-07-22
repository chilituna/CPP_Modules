/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:22:49 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/15 15:42:39 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& src);
		~Point(void);

		Point& operator=(const Point& src);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

#endif
