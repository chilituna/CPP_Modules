/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:33:41 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:30:27 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "Default FragTrap has been created.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap " << name << " has been created.\n";
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy constructor called.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	if (this == &copy)
		return (*this);
	ClapTrap::operator=(copy);
	std::cout << "FragTrap Copy assignment operator called.\n";
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " has been destroyed.\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is requesting a high five!\n";
}
