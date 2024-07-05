/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:31:01 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 12:43:54 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// create an array of Zombie instances on the heap
// delete (in main) will trigger the destuctor to clean allocated memory
Zombie* zombieHorde( int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return NULL;
	}
	Zombie *horde = new Zombie[N];
	if (horde == nullptr)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return NULL;
	}
	for(int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return horde;
}
