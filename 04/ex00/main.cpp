/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:08:32 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 16:57:48 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


int	main(void)
{
// BASIC TEST
	Animal*	animal = new Animal();
	Animal*	dog = new Dog();
	Animal*	cat = new Cat();
	std::cout << std::endl;

	std::cout << animal->getType() << ": ";
	animal->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;

// CAT COPY CONSTRUTOR TEST
	Cat* cat1 = new Cat;
	Cat* cat2 = new Cat(*cat1);
	std::cout << std::endl;

	std::cout << cat1->getType() << ": ";
	cat1->makeSound();
	std::cout << cat2->getType() << ": ";
	cat2->makeSound();
	std::cout << std::endl;

	delete cat1;
	delete cat2;
	std::cout << std::endl;

// DOG COPY ASSIGNMENT OPERATOR TEST
	Animal* dog1 = new Dog;
	Animal* dog2 = new Dog;

	*dog1 = *dog2;

	std::cout << dog1->getType() << ": ";
	dog1->makeSound();
	std::cout << dog2->getType() << ": ";
	dog2->makeSound();
	std::cout << std::endl;

	delete dog1;
	delete dog2;
	std::cout << std::endl;

// WRONG ANIMAL TEST
	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << wrongAnimal->getType() << ": ";
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << ": ";
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
