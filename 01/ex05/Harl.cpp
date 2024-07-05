/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:58:01 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 10:37:51 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I think there is something that could be done better here by debugging." << std::endl;
}

void Harl::info( void )
{
	std::cout << "For your information..." << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I am warning you!" << std::endl;
}

void Harl::error( void )
{
	std::cout << "3RR03!!! You have made a huge mistake!" << std::endl;
}

//create an array of pointers to member functions
//create as string array of possible levels
//iterate through levels, if match found, call the corresponding function
void Harl::complain( const std::string &level ) 
{
	void(Harl::*FuncPtr[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*FuncPtr[i])();
			return;
		}
	}
	std::cerr << "Level of complaint does not exist." << std::endl;

}