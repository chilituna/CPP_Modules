/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:13:17 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:30:52 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "Default ScavTrap has been created.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << name << " has been created.\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy constructor called.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	if (this == &copy)
		return (*this);
	ClapTrap::operator=(copy);
	std::cout << "ScavTrap Copy assignment operator called.\n";
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed.\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack because it has no hit points or energy points left.\n";
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage <<
		" points of damage!\n";
	this->_energy_points -= 1;
}
