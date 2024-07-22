/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:29:57 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/15 16:54:50 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Helper function to calculate the area of the triangle
Fixed area(Point const& a, Point const& b, Point const& c)
{
	Fixed result = Fixed(0.5f) * ((a.getX() * (b.getY() - c.getY())) +
                          (b.getX() * (c.getY() - a.getY())) +
                          (c.getX() * (a.getY() - b.getY())));
	if (result < 0)
		result = result * Fixed(-1);
	return result;
}


// check if a point is inside a triangle using the Barycentric coordinate system:
// if point is inside the triangle, the sum of the areas of the triangles formed with point
// and the sides of the main triangle should be equal to the area of the main triangle.
// Returns: True if the point is inside the triangle. False otherwise.
// Thus, if the point is a vertex or on edge, it will return False.

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = area(a, b, c);
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);

	// check if the point or on edge or vertex -> return false
	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
	{
		std::cout << "Point is on edge or vertex" << std::endl;
		return false;
	}

	std::cout << "Area ABC: " << areaABC.toFloat() << std::endl;
	std::cout << "Area PAB + PBC + PCA: " << (areaPAB + areaPBC + areaPCA).toFloat() << std::endl;
    return (areaABC == areaPAB + areaPBC + areaPCA);
}
