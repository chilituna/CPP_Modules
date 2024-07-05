/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:52:29 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 12:41:07 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name);

int main(void)
{

	int	size;

	size = 5;

	Zombie *horde = zombieHorde(size, "Zombie");
	if (horde == NULL)
		return 1;
	for(int i = 0; i < size; ++i)
	{
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}
