/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:42:18 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:24:56 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap	A("a");
	ScavTrap	B("b");
	ScavTrap	C("c");

	std::cout << std::endl;

	A.attack("B");
	B.takeDamage(10);
	std::cout << "ClapTrap A with name " << A.getName() << " has now "
		<< A.getHitpoints() << " hit points and "
		<< A.getEnergy() << " energy points.\n";
	std::cout << "ScavTrap B with name " << B.getName() << " has now "
		<< B.getHitpoints() << " hit points and "
		<< B.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	B.beRepaired(2);
	std::cout << "ScavTrap B with name " << B.getName() << " has now "
		<< B.getHitpoints() << " hit points and "
		<< B.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	std::cout << "ScavTrap C with name " << C.getName() << " has now "
		<< C.getHitpoints() << " hit points and "
		<< C.getEnergy() << " energy points.\n";
	C = B;
	std::cout << "ScavTrap C with name " << C.getName() << " has now "
		<< C.getHitpoints() << " hit points and "
		<< C.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	ScavTrap	D(B);
	std::cout << "ScavTrap D with name " << D.getName() << " has now "
		<< D.getHitpoints() << " hit points and "
		<< D.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	B.attack("A");
	A.takeDamage(20);
	std::cout << std::endl;

	B.guardGate();
	std::cout << std::endl;

	B.attack("A");
	A.takeDamage(20);
	std::cout << std::endl;

	B.beRepaired(10);
	std::cout << std::endl;
}
