/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:57:30 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/16 15:53:06 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

//CONSTRUCTORS AND DESTRUCTOR

AMateria::AMateria(void) : _type("unknown")
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria created with type " << type << std::endl;
}

AMateria::AMateria(const AMateria& copy) : _type(copy._type)
{
	std::cout << "AMateria copy constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	std::cout << "AMateria copy assignment operator called\n";
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destroyed.\n";
}

//GETTERS AND SETTERS

const std::string& AMateria::getType() const
{
	return this->_type;
}


// MEMBER FUNCTIONS

void AMateria::use(ICharacter& target)
{
	 std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}

