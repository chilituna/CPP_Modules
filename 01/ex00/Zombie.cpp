/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:19:06 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/29 15:10:31 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

//Constructor
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << GREEN_TEXT << name << " has been created\n" << RESET_TEXT;
}

//Destuctor
Zombie::~Zombie(void)
{
	std::cout << RED_TEXT << name << " has been destroyed\n" << RESET_TEXT;
}
