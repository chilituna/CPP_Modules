/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:42:10 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:01:46 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("anonym"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default ClapTrap has been created.\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << name << " has been created.\n";
}

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name), _hit_points(copy._hit_points),
	_energy_points(copy._energy_points), _attack_damage(copy._attack_damage)
{
	std::cout << "ClapTrap copy constructor called.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
	std::cout << "ClapTrap copy assignment operator called.\n";
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed.\n";
}

unsigned int	ClapTrap::getHitpoints(void)
{
	return (this->_hit_points);
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

unsigned int	ClapTrap::getEnergy(void)
{
	return (this->_energy_points);
}

// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back.
// Attacking and repairing cost 1 energy point each.
// ClapTrap can’t do anything if it has no hit points or energy points left.

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " can't attack because it has no hit points or energy points left.\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attack_damage << " points of damage!\n";
	this->_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " can't take damage because it has no hit points left.\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount
		<< " points of damage!\n";
	if (this->_hit_points <= amount)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points left.\n";
		this->_hit_points = 0;
		return ;
	}
	this->_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " can't be repaired because it has no hit points or energy points left.\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is being repaired for " << amount << " hit points!\n";
	this->_hit_points += amount;
	this->_energy_points -= 1;
}
