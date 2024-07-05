/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:33:52 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/22 15:04:25 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[1;36m"

int main(int argc, char **argv)
{
	if (argc == 1)
	std::cout << BLUE_TEXT "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << RESET_TEXT << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (int j = 0; j < (char)str.length(); j++)
			{
				std::cout << BLUE_TEXT << (char)std::toupper(str[j]);
			}
		}
		std::cout << RESET_TEXT << std::endl;
	}
}