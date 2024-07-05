/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:54:43 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/22 14:56:21 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int string_to_int(std::string str)
{
	int num = 0;
	std::stringstream ss;
	ss << str;
	ss >> num;
	if (ss.fail() || !ss.eof())
		return 0;
	return num;
}

std::string trim_whitespace(std::string str)
{
	int	start = 0;
	int	end = str.length() - 1;

	while (std::isspace(str[start]))
		start++;
	if (start == end + 1)
		return ("");
	while (std::isspace(str[end]))
		end--;
	return str.substr(start, end - start + 1);

}

//Make sure input is not empty
std::string get_input(std::string prompt)
{
	std::string input;

	while(input.empty())
	{
		std::cout << GREEN_TEXT << prompt << RESET_TEXT << std::endl;
		getline(std::cin, input);
		input = trim_whitespace(input);
		if (std::cin.eof())
			exit(1);
		if (input.empty())
			std::cout << RED_TEXT << "Invalid input, please try again." << RESET_TEXT << std::endl;
	}
	return (input);
}

//Truncate text to fit in the table
std::string truncated_text(std::string text)
{
	if (text.length() > 10)
	{
		text.resize(9);
		text.append(".");
	}
	return (text);
}





