/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:16:17 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 09:43:52 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// The new operator initializes the memory and returns the address
// of the new allocation, and initializes the block of memory
// to the variable pointer type.
// The zombie remains in memory until you explicitly delete it.
// This is useful for objects that need to persist beyond the scope
// in which they were created.
// However, you must remember to delete the object to avoid memory leaks.
Zombie* newZombie( std::string name )
{
	Zombie* z =  new Zombie(name);
	return (z);
}
