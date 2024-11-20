/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:28:23 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 16:40:21 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
		Animal::operator=(copy);
	std::cout << "Dog assignation operator called\n";
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog R.I.P.\n";
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof\n";
}
