/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:03:26 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/29 15:46:01 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// create a new Zombie on the heap and return a pointer to it
Zombie* newZombie (std::string name);

// create a new Zombie on the stack
void randomChump( std::string name );

int	main(void)
{
	Zombie	*zombie_heap = newZombie("Zombie Heap");
	zombie_heap->announce();
	randomChump("Zombie Stack");
	delete zombie_heap;
}
