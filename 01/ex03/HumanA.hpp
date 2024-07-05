/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:12:57 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/30 09:59:42 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

// Guaranteed Weapon: HumanA is designed to always have a weapon.
// Using a reference ensures that HumanA cannot exist without a weapon.

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(const std::string &name, Weapon &weapon);
		void attack() const;
};

#endif
