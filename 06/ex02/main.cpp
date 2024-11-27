/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:24:42 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/24 18:57:51 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Randomly instanciates A, B or C and returns the instance as a Base pointer.
Base* generate(void)
{
	srand(time(0));
	int random = std::rand() % 3;

	switch(random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}

}

// Prints the actual type of the object pointed to by p.
// Dynamic cast returns value of new type on success and null pointer on failure.
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown type";
}

// prints the actual type of the object pointed to by p.
// Dynamic cast returns bad_cast exception on failure.
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch(...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B";
		}
		catch(...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C";
			}
			catch(...)
			{
				std::cout << "Unknown type";
			}
		}
	}
}

int main(void)
{
	Base* base_ptr = generate();

	std::cout << "Identified type with pointer: ";
	identify(base_ptr);
	std::cout << std::endl;

	std::cout << "Identified type with reference: ";
	identify(*base_ptr);
	std::cout << std::endl;

	delete base_ptr;
}