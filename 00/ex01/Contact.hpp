/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:22:19 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/22 14:25:31 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

#define GREEN_TEXT "\033[1;32m"
#define RESET_TEXT "\033[0m"

class Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string secret;
	std::string phone_number;

	public:
		void set_first_name(std::string);
		void set_last_name(std::string);
		void set_nickname(std::string);
		void set_secret(std::string);
		void set_phone_number(std::string);

		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_secret();
		std::string get_phone_number();

		void print_contact();
};

#endif
