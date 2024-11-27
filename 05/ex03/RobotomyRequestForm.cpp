/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:41:17 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:27:08 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.

// ORTHODOX CANONICAL FORM

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy request", 72, 45)
{
	std::cout << "---RobotomyRequestForm default constructor called---" << std::endl;
	this->_target = "unnamed";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robotomy request", 72, 45)
{
	std::cout << "---RobotomyRequestForm constructor called---" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("Robotomy request", 72, 45)
{
	std::cout << "---RobotomyRequestForm copy constructor called---" << std::endl;
	this->_target = other._target;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "---RobotomyRequestForm copy assignment constructor called---" << std::endl;
	if (this != &other)
		this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "---RobotomyRequestForm destructor called---" << std::endl;
}


// GETTERS
const std::string& RobotomyRequestForm::getTarget()const
{
	return this->_target;
}


// MEMBER FUNCTIONS

void RobotomyRequestForm::execute() const
{
	srand(time(0)); // to make sure to generate random number every time

	std::cout << "Brrrrzzzzrzrrzrrrr Drrrrrrtrrtttrtrrrrrrrrr" << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "The robotomy of " << _target << " has failed!" << std::endl;
	}
}


// OPERATOR OVERLOADING ADDON

void RobotomyRequestForm::appendToStream(std::ostream& os) const
{
	os << "Target: " << this-> _target << std::endl;
}
