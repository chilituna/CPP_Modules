/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:22:04 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/22 14:49:09 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include <stdlib.h>
#include "Contact.hpp"

#define GREEN_TEXT "\033[1;32m"
#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[1;36m"

//helper_functions
std::string trim_whitespace(std::string);
std::string get_input(std::string);
std::string truncated_text(std::string);

class PhoneBook
{
		Contact contacts[8];

		public:
			void add_contact(int);
			void print_saved_contacts();
			void display_contact(int);
};

#endif
