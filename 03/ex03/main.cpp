/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:42:18 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 13:53:48 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int		main(void)
{
	DiamondTrap	A("diA");
	DiamondTrap B("diB");

	std::cout << std::endl;

	std::cout << "A has " << A.getHitpoints() << " hitpoints\n";
	std::cout << "A has " << A.getEnergy() << " energy\n";
	std::cout << "A has " << A.getAttack() << " attack damage\n";
	std::cout << std::endl;

	A.attack("B");
	B.takeDamage(30);
	std::cout << A.getName() << " has " << A.getHitpoints() << " hitpoints and " << A.getEnergy() << " energy points\n";
	std::cout << B.getName() << " has " << B.getHitpoints() << " hitpoints and " << B.getEnergy() << " energy points\n";
	std::cout << std::endl;

	A.whoAmI();
	B.whoAmI();
	std::cout << std::endl;

	DiamondTrap C(A);
	C.whoAmI();
	std::cout << "C has " << C.getHitpoints() << " hitpoints\n";
	std::cout << "C has " << C.getEnergy() << " energy\n";
	std::cout << "C has " << C.getAttack() << " attack damage\n";
	std::cout << std::endl;

	C = B;
	C.whoAmI();
	std::cout << "C has " << C.getHitpoints() << " hitpoints\n";
	std::cout << "C has " << C.getEnergy() << " energy\n";
	std::cout << "C has " << C.getAttack() << " attack damage\n";
	std::cout << std::endl;

	C = A;
	C.whoAmI();
	std::cout << "C has " << C.getHitpoints() << " hitpoints\n";
	std::cout << "C has " << C.getEnergy() << " energy\n";
	std::cout << "C has " << C.getAttack() << " attack damage\n";
	std::cout << std::endl;















}
