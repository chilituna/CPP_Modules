/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:42:18 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:00:40 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	A("a");
	ClapTrap	B;
	ClapTrap	C("c");
	C = A;
	ClapTrap	D(A);

	std::cout << std::endl;

	A.attack("B");
	B.takeDamage(5);
	std::cout << "ClapTrap A with name \"" << A.getName() << "\" has now "
		<< A.getHitpoints() << " hit points and "
		<< A.getEnergy() << " energy points.\n";
	std::cout << "ClapTrap B with name \"" << B.getName() << "\" has now "
		<< B.getHitpoints() << " hit points and "
		<< B.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	C.attack("B");
	B.takeDamage(4);
	std::cout << "ClapTrap C with name \"" << C.getName() << "\" has now "
		<< C.getHitpoints() << " hit points and "
		<< C.getEnergy() << " energy points.\n";
	std::cout << "ClapTrap B with name \"" << B.getName() << "\" has now "
		<< B.getHitpoints() << " hit points and "
		<< B.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	B.beRepaired(2);
	std::cout << "ClapTrap B with name \"" << B.getName() << "\" has now "
		<< B.getHitpoints() << " hit points and "
		<< B.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	A.attack("B");
	B.takeDamage(5);
	std::cout << "ClapTrap A with name \"" << A.getName() << "\" has now "
		<< A.getHitpoints() << " hit points and "
		<< A.getEnergy() << " energy points.\n";
	std::cout << "ClapTrap B with name \"" << B.getName() << "\" has now "
		<< B.getHitpoints() << " hit points and "
		<< B.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	B.attack("A");
	std::cout << std::endl;

	A.attack("B");
	B.takeDamage(5);
	std::cout << "ClapTrap A with name \"" << A.getName() << "\" has now "
		<< A.getHitpoints() << " hit points and "
		<< A.getEnergy() << " energy points.\n";
	std::cout << "ClapTrap B with name \"" << B.getName() << "\" has now "
		<< B.getHitpoints() << " hit points and "
		<< B.getEnergy() << " energy points.\n";
	std::cout << std::endl;

	A.attack("B");
	A.attack("B");
	A.attack("B");
	A.attack("B");
	A.attack("B");
	A.attack("B");
	A.attack("B");
	A.attack("B");
	std::cout << std::endl;

	D.attack("C");
	C.takeDamage(10);
	std::cout << std::endl;
}
