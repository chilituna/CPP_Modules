/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:10:30 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/16 16:46:08 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

//CONSTRUCTORS AND DESTRUCTOR

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
	std::cout << "Ice copy constructor called\n";
}

Ice& Ice::operator=(const Ice& copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	std::cout << "Ice copy assignment operator called\n";
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destroyed\n";
}


// MEMBER FUNCTIONS

AMateria* Ice::clone() const
{
	std::cout << "Ice was cloned\n";
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
