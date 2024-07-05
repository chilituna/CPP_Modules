/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:08:01 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 09:45:00 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


// Zombie is created in stack and automatically destroyed
// when the function returnd.
// This is efficient and convenient for temporary objects
// that are only needed within a specific scope.
void randomChump( std::string name )
{
	Zombie z = Zombie(name);
	z.announce();
}
