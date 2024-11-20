/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:10:55 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/16 16:46:13 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// CONSTRUCTORS AND DESTRUCTOR

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
	std::cout << "Cure copy constructor called\n";
}

Cure& Cure::operator=(const Cure& copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	std::cout << "Cure copy assignment operator calle \n";
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destroyed\n";
}

// MEMBER FUNCTIONS

AMateria* Cure::clone() const
{
	std::cout << "Cure got cloned\n";
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}