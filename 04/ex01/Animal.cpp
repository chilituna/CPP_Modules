/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:10:47 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 16:59:07 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		_type = copy._type;
	std::cout << "Animal assignation operator called\n";
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " has been destroyed.\n";
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound\n";
}
