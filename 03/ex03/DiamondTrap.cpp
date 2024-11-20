/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:45:24 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:51:22 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default")
{
	this->_hit_points = FragTrap::_hit;
	this->_energy_points = ScavTrap::_energy;
	this->_attack_damage = FragTrap:: _attack;
	std::cout << "Default DiamondTrap created.\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->_hit_points = FragTrap::_hit;
	this->_energy_points = ScavTrap::_energy;
	this->_attack_damage = FragTrap:: _attack;
	std::cout << "DiamondTrap " << _name << " created.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	if (this == &copy)
		return *this;
	ClapTrap::operator=(copy);
	this->_name = copy._name;
	std::cout << "DiamontTrap copy assignment operator called.\n";
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destroyed.\n";
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}