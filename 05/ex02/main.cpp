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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main ()
{
	//SHUBBERY
	try
	{
		// create a bureaucrat
		Bureaucrat alise(146, "Alise");

		// create shrubbery form
		// Required grades: sign 145, exec 137
		ShrubberyCreationForm shrubbery("tree");

		alise.signForm(shrubbery);
		alise.executeForm(shrubbery);

		alise.incrementGrade();
		std::cout << std::endl;

		alise.signForm(shrubbery);
		alise.executeForm(shrubbery);

		std::cout << std::endl;

		// create a bureaucrat that has higher grade to execute
		Bureaucrat xavier(100, "Xavier");

		xavier.executeForm(shrubbery);
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

	//ROBOTOMY
	try
	{
		// create a bureaucrat
		Bureaucrat alise(73, "Alise");

		// create robotomy form
		// Required grades: sign 72, exec 45
		RobotomyRequestForm robotomy("paranoia");

		alise.signForm(robotomy);
		alise.executeForm(robotomy);

		alise.incrementGrade();
		std::cout << std::endl;

		alise.signForm(robotomy);
		alise.executeForm(robotomy);

		std::cout << std::endl;

		// create a bureaucrat that has higher grade to execute
		Bureaucrat xavier(45, "Xavier");

		xavier.executeForm(robotomy);
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

	//PARDON
	try
	{
		// create a bureaucrat
		Bureaucrat alise(26, "Alise");

		// create robotomy form
		// Required grades: sign 25, exec 5
		PresidentialPardonForm pardon("pardon");

		alise.signForm(pardon);
		alise.executeForm(pardon);

		alise.incrementGrade();
		std::cout << std::endl;

		alise.signForm(pardon);
		alise.executeForm(pardon);

		std::cout << std::endl;

		// create a bureaucrat that has higher grade to execute
		Bureaucrat xavier(5, "Xavier");

		xavier.executeForm(pardon);
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


