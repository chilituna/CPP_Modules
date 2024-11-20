/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:10:47 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 17:21:34 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	if (this != &copy)
		_type = copy._type;
	std::cout << "Animal assignation operator called\n";
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal " << this->_type << " has been destroyed.\n";
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
