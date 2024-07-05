/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:57:28 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 10:00:52 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(const std::string &type);
		const std::string& getType() const;
		void setType(const std::string &newType);
};

// constant reference to a string ensures that the argument passed to the constructor is not modified
// within the constructor, which is a good practice and prevents unintended side effects.
// Passing the string by reference (instead of by value) avoids copying the string, which can be expensive
// in terms of performance, especially for large strings.

// Returning a const std::string& ensures that the caller cannot modify the private type attribute
// of the Weapon class. It enforces read-only access.
// The const at the end of the method (getType() const) signifies that this method does not modify
// the state of the object. This means it guarantees not to change any member variables of the class,
// making it safe to call on constant instances of the Weapon class.


#endif
