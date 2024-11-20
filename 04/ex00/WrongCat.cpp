/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:31:40 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/01 19:41:48 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat assignation operator called\n";
	if (this == &copy)
		return (*this);
	WrongAnimal::operator=(copy);
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat R.I.P.\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "Ding Dong!\n";
}
