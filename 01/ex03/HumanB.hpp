/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:25:43 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 10:03:45 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

// Optional Weapon: HumanB can exist without a weapon, and the weapon can be
// dynamically assigned or changed by manipulating the pointer.
// The pointer can be nullptr, indicating that HumanB currently has no weapon.

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(const std::string &name);
		void setWeapon(Weapon &weapon);
		void attack() const;
};

#endif
