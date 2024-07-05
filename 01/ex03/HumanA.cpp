/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:41:15 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/30 09:26:16 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name(name), weapon(weapon) {}

void HumanA::attack() const
{
	std::cout << name << " attacks with their weapon " << weapon.getType() << std::endl;
}


