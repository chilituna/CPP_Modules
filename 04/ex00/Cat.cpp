/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:53:01 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 16:39:45 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
		Animal::operator=(copy);
	std::cout << "Cat assignation operator called\n";
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat R.I.P.\n";
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
