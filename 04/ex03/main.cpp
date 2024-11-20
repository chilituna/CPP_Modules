/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:00:58 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/16 17:45:54 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
IMateriaSource* src = new MateriaSource();
std::cout << std::endl;

std::cout << " Learned materias: \n";
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << src->getMaterias(i) << std::endl;
std::cout << std::endl;

src->learnMateria(new Ice());
std::cout << " Learned materias: \n";
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << src->getMaterias(i) << std::endl;
std::cout << std::endl;

src->learnMateria(new Cure());
std::cout << " Learned materias: \n";
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << src->getMaterias(i) << std::endl;
std::cout << std::endl;

ICharacter* me = new Character("me");
std::cout << std::endl;

AMateria* tmp;
tmp = src->createMateria("ice");
std::cout << std::endl;

me->equip(tmp);
std::cout << me->getName() << " is equipped with: \n";
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << me->getInventory(i) << std::endl;
std::cout << std::endl;

tmp = src->createMateria("cure");
std::cout << std::endl;

me->equip(tmp);
std::cout << me->getName() << " is equipped with: \n";
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << me->getInventory(i) << std::endl;
std::cout << std::endl;

ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
std::cout << std::endl;

tmp = src->createMateria("ice");
std::cout << std::endl;

std::cout << bob->getName() << " is equipped with: \n";
bob->equip(tmp);
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << bob->getInventory(i) << std::endl;
std::cout << std::endl;

tmp = src->createMateria("ice");
bob->equip(tmp);
tmp = src->createMateria("ice");
bob->equip(tmp);
tmp = src->createMateria("ice");
bob->equip(tmp);
tmp = src->createMateria("ice");
bob->equip(tmp);
delete tmp;
std::cout << bob->getName() << " is equipped with: \n";
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << bob->getInventory(i) << std::endl;
std::cout << std::endl;

bob->use(0, *me);
std::cout << std::endl;

bob->unequip(0);
bob->unequip(5);
std::cout << bob->getName() << " is equipped with: \n";
for (int i = 0; i < 4; i++)
	std::cout << i << ": " << bob->getInventory(i) << std::endl;
std::cout << std::endl;

bob->use(0, *me);

delete bob;
delete me;
delete src;
std::cout << std::endl;

return 0;
}