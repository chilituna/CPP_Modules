/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:40:38 by aarponen          #+#    #+#             */
/*   Updated: 2025/01/18 17:05:25 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid input. Usage: ./RPN  \"RPN expression\"." << std::endl;
		return 1;
	}

	try
	{
		Rpn	rpn;
		std::cout << rpn.calculate(argv[1]) << std::endl;

	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "[Invalid Argument Error] " << e.what() << '\n';
		return 1;
	}
	catch (const std::domain_error& e)
	{
		std::cerr << "[Domain Error] " << e.what() << '\n';
		return 1;
	}
	catch (const std::logic_error& e)
	{
		std::cerr << "[Logic Error] " << e.what() << '\n';
		return 1;
	}
	catch (const std::exception& e)  // Catch any other std::exception
	{
		std::cerr << "[General Error] " << e.what() << '\n';
		return 1;
	}

	return 0;
}