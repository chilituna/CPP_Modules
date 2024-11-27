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
#include <iostream>

int main ()
{
	int	starting_grade = 1;

	std::cout << std::endl;


// create a bureaucrat, increase and decrease grade.
	try
	{
		Bureaucrat	john(starting_grade, "John");
		std::cout << john << std::endl;

		john.decrementGrade();
		std::cout << "After decrement: " << john << std::endl;

		john.incrementGrade();
		std::cout << "After increment: " << john << std::endl;

		john.incrementGrade();
		std::cout << "After increment: " << john << std::endl;
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

// // bureaucrat should not be created without name and grade (compiling error due to private default constructor)
// 	try
// 	{
// 		Bureaucrat	paul;
// 	}
// 	catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

// initializing with too low grade
	try
	{
		Bureaucrat	george(151, "George");
		std::cout << george << std::endl;
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

// copying the bureacrat (constant name remains)
	try
	{
		Bureaucrat	george(3, "George");
		std::cout << george << std::endl;
		Bureaucrat	john(100, "John");
		std::cout << john << std::endl;
		john = george;
		std::cout << george << std::endl;
		std::cout << john << std::endl;
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


