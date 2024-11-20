/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:08:32 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 17:30:36 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>


int	main(void)
{

// TEST: instance cannot be created from abstract class:
	// AAnimal	test;

// BASIC TEST WITH ANIMAL ARRAY
	const int 	n = 6;
	AAnimal*	animals[n];
	std::cout << std::endl;

	for (int i = 0; i < (n / 2); i++)
	{
		animals[i] = new Dog();
	}
	for (int i = (n / 2); i < n; i++)
	{
		animals[i] = new Cat();
	}
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		delete animals[i];
	}
	std::cout << std::endl;

// CAT DEEP COPY WITH ASSIGNMENT OPERATOR
	Cat* cat1 = new Cat();
	cat1->setBrainIdea("I want food", 1);
	cat1->makeSound();
	std::cout << cat1->getBrainIdea(1) << std::endl;
	std::cout << std::endl;

	Cat* cat2 = new Cat;
	*cat2 = *cat1;
	std::cout << "Cat1 says: "<< cat1->getBrainIdea(1) << std::endl;
	std::cout << "Cat2 says: "<< cat2->getBrainIdea(1) << std::endl;
	std::cout << std::endl;

	cat1->setBrainIdea("purr purr", 1);
	std::cout << "Cat1 says: "<< cat1->getBrainIdea(1) << std::endl;
	std::cout << "Cat2 says: "<< cat2->getBrainIdea(1) << std::endl;
	std::cout << std::endl;

	delete cat1;
	delete cat2;
	std::cout << std::endl;


// DOG DEEP COPY WITH COPY CONSTRUCTOR
	Dog* dog1 = new Dog;
	dog1->setBrainIdea("Let's play", 5);
	std::cout << std::endl;

	Dog* dog2 = new Dog(*dog1);
	std::cout << "Dog1 says: "<< dog1->getBrainIdea(5) << std::endl;
	std::cout << "Dog2 says: "<< dog2->getBrainIdea(5) << std::endl;
	std::cout << std::endl;

	dog1->setBrainIdea("ZZzzzzzZZ", 5);
	std::cout << "Dog1 says: "<< dog1->getBrainIdea(5) << std::endl;
	std::cout << "Dog2 says: "<< dog2->getBrainIdea(5) << std::endl;
	std::cout << std::endl;

	delete dog1;
	delete dog2;
	std::cout << std::endl;

	return 0;
}

