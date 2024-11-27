/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:49:19 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:35:56 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// ORTHODOX CANONICAL FORM

Intern::Intern()
{
	std::cout << "---Intern default constructor called.---" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "---Intern copy constructor called.---" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "---Intern copy assignment called.---" << std::endl;
	return *this;
}
Intern::~Intern()
{
	std::cout << "---Intern destructor called.---" << std::endl;
}


// EXCEPTION CLASS
const char* Intern::NonExistingFormException::what(void) const throw()
{
	return "Requested form does not exist.";
}


// HELPER FUNCTIONS TO CREATE FORMS

AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}


// MEMBER FUNCTIONS

AForm* Intern::makeForm(std::string name, std::string target)
{
	const std::string form_names[] = { "presidental pardon", "robotomy request", "shrubbery creation" };
	AForm* (*formCreators[])(const std::string&) = { createPardon, createRobotomy, createShrubbery };


	for (int i = 0; i < 3; i++)
	{
		if (form_names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return formCreators[i](target);
		}
	}
	throw NonExistingFormException();
}
