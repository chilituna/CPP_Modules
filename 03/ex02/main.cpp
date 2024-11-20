/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:42:18 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:36:15 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	ClapTrap	claptrap("Clapi");
	ScavTrap	scavtrap("Scavi");
	FragTrap	fragtrap("Fragi");

	std::cout << std::endl;

	claptrap.attack("Scavi");
	scavtrap.takeDamage(10);
	std::cout << "ClapTrap " << claptrap.getName() << " has now "
		<< claptrap.getHitpoints() << " hit points and "
		<< claptrap.getEnergy() << " energy points.\n";
	std::cout << "ScavTrap " << scavtrap.getName() << " has now "
		<< scavtrap.getHitpoints() << " hit points and "
		<< scavtrap.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	scavtrap.attack("Clapi");
	claptrap.takeDamage(20);
	std::cout << "ClapTrap " << claptrap.getName() << " has now "
		<< claptrap.getHitpoints() << " hit points and "
		<< claptrap.getEnergy() << " energy points.\n";
	std::cout << "ScavTrap " << scavtrap.getName() << " has now "
		<< scavtrap.getHitpoints() << " hit points and "
		<< scavtrap.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	scavtrap.guardGate();
	std::cout << std::endl;

	scavtrap.attack("Fragi");
	fragtrap.takeDamage(20);
	std::cout << "FragTrap " << fragtrap.getName() << " has now "
		<< fragtrap.getHitpoints() << " hit points and "
		<< fragtrap.getEnergy() << " energy points.\n";
	std::cout << "ScavTrap " << scavtrap.getName() << " has now "
		<< scavtrap.getHitpoints() << " hit points and "
		<< scavtrap.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	fragtrap.highFivesGuys();
	std::cout << std::endl;

	fragtrap.attack("Scavi");
	scavtrap.takeDamage(30);
	std::cout << "FragTrap " << fragtrap.getName() << " has now "
		<< fragtrap.getHitpoints() << " hit points and "
		<< fragtrap.getEnergy() << " energy points.\n";
	std::cout << "ScavTrap " << scavtrap.getName() << " has now "
		<< scavtrap.getHitpoints() << " hit points and "
		<< scavtrap.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	scavtrap.beRepaired(10);
	std::cout << "ScavTrap " << scavtrap.getName() << " has now "
		<< scavtrap.getHitpoints() << " hit points and "
		<< scavtrap.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	FragTrap frag2(fragtrap);

	std::cout << "FragTrap 2 " << frag2.getName() << " has now "
		<< frag2.getHitpoints() << " hit points and "
		<< frag2.getEnergy() << " energy points.\n";
	frag2.highFivesGuys();
	std::cout << std::endl;

	FragTrap frag3;

	std::cout << "FragTrap 3 " << frag3.getName() << " has now "
		<< frag3.getHitpoints() << " hit points and "
		<< frag3.getEnergy() << " energy points.\n";
	frag3.highFivesGuys();
	std::cout << std::endl;

	frag3 = frag2;
	std::cout << "FragTrap 3 " << frag3.getName() << " has now "
		<< frag3.getHitpoints() << " hit points and "
		<< frag3.getEnergy() << " energy points.\n";
	frag3.highFivesGuys();
	std::cout << std::endl;

}
