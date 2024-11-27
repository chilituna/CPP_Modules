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
#include "Intern.hpp"
#include <iostream>

int main ()
{
	try
	{
		// create intern
		Intern intern;
		std::cout << std::endl;

		// intern makes robotomy
		AForm* form1 = intern.makeForm("robotomy request", "file_1");
		std::cout << *form1;
		delete form1;
		std::cout << std::endl;

		// intern makes shrubbery
		AForm* form2 = intern.makeForm("shrubbery creation", "file_2");
		std::cout << *form2;
		delete form2;
		std::cout << std::endl;

		// intern makes pardon
		AForm* form3 = intern.makeForm("presidental pardon", "file_3");
		std::cout << *form3;
		delete form3;
		std::cout << std::endl;

		// intern tries to make form that does not exist
		AForm* form4 = intern.makeForm("test", "wrong_name");
		std::cout << *form4;
		delete form4;
		std::cout << std::endl;
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