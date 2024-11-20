/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:49:09 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/16 17:44:37 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//CONSTRUCTORS AND DESCTRUCTOR

Character::Character() : _name("Unnamed")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < 10; ++i)
		_dropped[i] = NULL;
	std::cout << "Default Character constructor called\n";
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < 10; ++i)
		_dropped[i] = NULL;
	std::cout << "Character constructor called with name: " << name << std::endl;
}

Character::Character(const Character& copy) : _name(copy._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 10; ++i)
		_dropped[i] = NULL;
	std::cout << "Character copy constructor called\n";
}

Character& Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
		for (int i = 0; i < 10; ++i)
		{
			if (this->_dropped[i])
				delete this->_dropped[i];
		}
		_name = copy._name;
		for (int i = 0; i < 4; ++i)
		{
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		for (int i = 0; i < 10; ++i)
			_dropped[i] = NULL;
	}
	std::cout << "Character copy assignment constructor called\n";
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
	for (int i = 0; i < 10; ++i)
		{
			if (this->_dropped[i])
				delete this->_dropped[i];
		}
	std::cout << "Character destroyed\n";
}

// GETTERS AND SETTERS

const std::string& Character::getName() const
{
	return this->_name;
}

const std::string& Character::getInventory(int i) const
{
	static const std::string emptyString = "";
	if ( i >= 0 && i < 4 && this->_inventory[i])
		return this->_inventory[i]->getType();
	return emptyString;
}

// MEMBER FUNCTIONS

// The Character possesses an inventory of 4 slots, which means 4 Materias at most.
// The inventory is empty at construction. They equip the Materias in the first empty slot
// they find. This means, in this order: from slot 0 to slot 3. In case they try to add
// a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything
// (but still, bugs are forbidden). The unequip() member function must NOT delete the
// Materia!

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		int i = 0;
		while (this->_dropped[i])
		{
			i++;
			if (i == 10)
			{
				std::cout << "Cannot be dropped, there is no more space on the floor\n";
				return ;
			}
		}
		this->_dropped[i] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
