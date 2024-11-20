/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:53:01 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 17:24:46 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal(), _brain(new Brain())
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& copy) : AAnimal(copy)
{
	this->_brain = new Brain(*copy._brain); // Deep copy
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		delete this->_brain; // delete old brain
		this->_brain = new Brain(*copy._brain); // Deep copy
	}
	std::cout << "Cat assignation operator called\n";
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat R.I.P.\n";
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}

void Cat::setBrainIdea(std::string idea, int i)
{
    this->_brain->setIdeas(idea, i);
}

std::string Cat::getBrainIdea(int i) const
{
    return this->_brain->getIdeas(i);
}