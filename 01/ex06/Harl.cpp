/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:58:01 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/01 21:16:06 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I think there is something that could be done better here.\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "For your information...\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I am warning you!\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "3RR03!!! You have made a huge mistake!\n" << std::endl;
}

// create an array of pointers to member functions
// create as string array of possible levels
// iterate through levels, if match found, store the level to start
// use switch to start executing the functiond from the level_index
void Harl::complain( std::string level )
{
	void(Harl::*FuncPtr[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	const std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	int	level_index = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			level_index = i;
			break;
		}
	}

	switch(level_index)
	{
		case 0:
			(this->*FuncPtr[0])();
			// Fall through
		case 1:
			(this->*FuncPtr[1])();
			// Fall through
		case 2:
			(this->*FuncPtr[2])();
			// Fall through
		case 3:
			(this->*FuncPtr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}