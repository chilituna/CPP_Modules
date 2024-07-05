/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:28:02 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/21 23:25:35 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Setters_
void Contact::set_first_name(std::string first_name){ this->first_name = first_name; }
void Contact::set_last_name(std::string last_name){ this->last_name = last_name; }
void Contact::set_nickname(std::string nickname){ this->nickname = nickname; }
void Contact::set_secret(std::string secret){ this->secret = secret; }
void Contact::set_phone_number(std::string phone_number){ this->phone_number = phone_number; }

//Getters_
std::string Contact::get_first_name(){ return (first_name); }
std::string Contact::get_last_name(){ return (last_name); }
std::string Contact::get_nickname(){ return (nickname); }
std::string Contact::get_secret(){ return (secret); }
std::string Contact::get_phone_number(){ return (phone_number); }

//Print the selected contact
void Contact::print_contact()
{
	std::cout << GREEN_TEXT << "First name: "<< first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number <<  std::endl;
	std::cout << "Darkest secret: " << secret << RESET_TEXT << std::endl;
}
