/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:07:50 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 10:01:40 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//constructor
Weapon::Weapon (const std::string &type)
	: type(type) {}


//getter and setter
const std::string& Weapon::getType() const
{
	return type;
}
void Weapon::setType(const std::string &newType)
{
	type = newType;
}
