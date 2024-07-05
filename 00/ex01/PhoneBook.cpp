/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:22:04 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/21 23:23:24 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add_contact(int index)
{
	Contact new_contact;
	std::string input;

	new_contact.set_first_name(get_input("First name: "));
	new_contact.set_last_name(get_input("Last name: "));
	new_contact.set_nickname(get_input("Nickname: "));
	new_contact.set_phone_number(get_input("Phone number: "));
	new_contact.set_secret(get_input("Darkest secret: "));

	contacts[index] = new_contact;
}

void PhoneBook::print_saved_contacts()
{
	int index = 0;

	while (index < 8)
	{
		if (contacts[index].get_first_name().empty())
			break;
		std::cout << GREEN_TEXT << std::setw(10) << std::right<< index + 1 << "|";
		std::cout << std::setw(10) << std::right << truncated_text(contacts[index].get_first_name()) << "|";
		std::cout << std::setw(10) << std::right << truncated_text(contacts[index].get_last_name()) << "|";
		std::cout << std::setw(10) << std::right << truncated_text(contacts[index].get_nickname()) << RESET_TEXT << std::endl;
		index++;
	}
}

void PhoneBook::display_contact(int index)
{
	contacts[index].print_contact();
}
