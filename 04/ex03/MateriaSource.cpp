/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:35:48 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/16 17:02:25 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//CONSTRUCTORS AND DESTRUCTOR

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
	std::cout << "MateriaSource default constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._templates[i])
			this->_templates[i] = copy._templates[i]->clone();
		else
			this->_templates[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_templates[i])
				delete this->_templates[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (copy._templates[i])
				this->_templates[i] = copy._templates[i]->clone();
			else
				this->_templates[i] = NULL;
		}
	}
	std::cout << "MateriaSource copy assign operator called\n";
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		{
			if (this->_templates[i])
				delete this->_templates[i];
		}
	std::cout << "MateriaSource destroyed\n";
}

// GETTERS AND SETTERS
const std::string& MateriaSource::getMaterias(int i) const
{
	static const std::string emptyString = "";
	if ( i >= 0 && i < 4 && this->_templates[i])
		return this->_templates[i]->getType();
	return emptyString;
}



//MEMBER FUNCTIONS

// Copies the Materia passed as a parameter and store it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique.
void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_templates[i])
		{
			this->_templates[i] = m;
			break;
		}
	}
}

// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.
AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] && this->_templates[i]->getType() == type)
			return this->_templates[i]->clone();
	}
	return NULL;
}
