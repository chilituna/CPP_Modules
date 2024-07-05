/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:56:06 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/22 14:26:44 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int string_to_int(std::string);

int	main()
{
	std::string input;
	PhoneBook phonebook;
	int added_contacts = 0;
	int index = 1;
	int max = 0;

	while(true)
	{
		std::cout << BLUE_TEXT << "Enter command (ADD / SEARCH / EXIT): " << RESET_TEXT << std::endl;
		getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input == "ADD")
		{
			if (added_contacts >= 8)
				std::cout << RED_TEXT << "Phonebook is full! Oldest contact will be overwritten." << RESET_TEXT << std::endl;
			index = added_contacts % 8 + 1;
			phonebook.add_contact(index - 1);
			added_contacts++;
		}
		else if (input == "SEARCH")
		{
			phonebook.print_saved_contacts();
			if (added_contacts == 0)
			{
				std::cout << RED_TEXT << "Phonebook is empty!" << RESET_TEXT << std::endl;
				continue;
			}
			do
			{
				std::cout << BLUE_TEXT << "Enter the index of the contact to display: " << RESET_TEXT << std::endl;
				getline(std::cin, input);
				if (std::cin.eof())
					return 0;
				index = string_to_int(input);
				if (added_contacts > 8)
					max = 8;
				else
					max = added_contacts;
				if (index < 1 || index > max)
					std::cout << RED_TEXT << "Invalid index!" << RESET_TEXT << std::endl;
			} while ((index < 1 || index > max));
			phonebook.display_contact(index - 1);
		}
		else if (input == "EXIT")
			return 0;
		else
			std::cout << RED_TEXT << "Invalid command!" << RESET_TEXT << std::endl;
	}
	return 0;
}
