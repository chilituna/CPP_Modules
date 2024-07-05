/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:43:21 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/01 15:36:24 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

#include <iostream>
#include <string>

int	main (int argc, const char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED << "Incorrect input! Usage: " << argv[0] << " <filename> <s1> <s2>\n" << RESET;
		return 1;
	}
	try
	{
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];

		Replace replace(filename, s1, s2);
		replace.replaceString();
	}
	catch(std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
