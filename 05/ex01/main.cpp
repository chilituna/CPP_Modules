/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:
0}+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:58:03 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/14 21:56:37 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main ()
{
	std::cout << std::endl;

	try
	{
		//create buroucrat
		Bureaucrat	john(101, "John");
		std::cout << john << std::endl;

		//create form
		Form 	a1("A1", 100, 10);
		std::cout << a1 << std::endl;

		//try to sign (grade is too low)
		john.signForm(a1);
		std::cout << a1 << std::endl;

		//increase grade
		john.incrementGrade();
		std::cout << john << std::endl;

		//signing whould now work
		john.signForm(a1);
		std::cout << a1 << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
    	std::cerr << "Caught an unknown exception!" << std::endl;
	}
	std::cout << std::endl;

	try
	{
		//try to create form with too high/low grade.
		// Form 	low1("low", 151, 1);
		// Form 	low2("low", 1, 151);
		// Form 	hi1("high", 0, 150);
		Form 	hi2("high", 150, 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
    	std::cerr << "Caught an unknown exception!" << std::endl;
	}
	std::cout << std::endl;
}


