/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:28:23 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 17:25:18 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal(), _brain(new Brain())
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& copy) : AAnimal(copy)
{
	this->_brain = new Brain(*copy._brain); // Deep copy
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		delete this->_brain; // delete old brain
		this->_brain = new Brain(*copy._brain); // Deep copy
	}
	std::cout << "Dog assignment operator called\n";
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog R.I.P.\n";
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof\n";
}

void Dog::setBrainIdea(std::string idea, int i)
{
	this->_brain->setIdeas(idea, i);
}

std::string Dog::getBrainIdea(int i) const
{
	return this->_brain->getIdeas(i);
}