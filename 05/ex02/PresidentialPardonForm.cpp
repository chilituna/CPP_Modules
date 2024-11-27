/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:10:32 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:42:42 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox

// ORTHODOX CANONICAL FORM

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential pardon", 25, 5)
{
	std::cout << "---PresidentialPardonForm default constructor called---" << std::endl;
	this->_target = "unnamed";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("Presidential pardon", 25, 5)
{
	std::cout << "---PresidentialPardonForm constructor called---" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm("Presidential pardon", 25, 5)
{
	std::cout << "---PresidentialPardonForm copy constructor called---" << std::endl;
	this->_target = other._target;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "---PresidentialPardonForm copy assignment constructor called---" << std::endl;
	if (this != &other)
		this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "---PresidentialPardonForm destructor called---" << std::endl;
}


// GETTERS
const std::string& PresidentialPardonForm::getTarget()const
{
	return this->_target;
}


// MEMBER FUNCTIONS
void PresidentialPardonForm::execute() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}