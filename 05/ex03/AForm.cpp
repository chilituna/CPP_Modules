/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:18:04 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:31:08 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// ORTHODOX CANONICAL FORM
// Default constructor omitted intentionally to enforce initialization with name and grades
// Copy assignment is also omitted, as copying constant values is not meaningful in this context.

AForm::AForm(std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(false)
{
	std::cout << "---Form constructor called.---" << std::endl;
	if (_sign_grade < 1 or _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 or _exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade), _is_signed(false)
{
	std::cout << "---Copy Form constructor called.---" << std::endl;
}

AForm::~AForm()
{
	std::cout << "---Form destructor called.---" << std::endl;
}


// GETTERS

const std::string& AForm::getName() const
{
	return this->_name;
}

bool AForm::getSignedStatus() const
{
	return this->_is_signed;
}

int AForm::getSignGrade() const
{
	return this->_sign_grade;
}

int AForm::getExecGrade() const
{
	return this->_exec_grade;
}


// MEMBER FUNCTIONS

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooLowException();
	this->_is_signed = true;
}

void AForm::beExecuted(const Bureaucrat& executor) const
{
	if (!this->_is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_exec_grade)
		throw GradeTooLowException();
	this->execute();
}


// EXCEPTION CLASSES

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}
const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}


// OPERATOR OVERLOADING

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	std::string status = form.getSignedStatus() ? "signed" : "not signed";

	os << "Form: " << form.getName() << std::endl
		<< "Grade required to sign: " << form.getSignGrade() << std::endl
		<< "Grade required to execute: " << form.getExecGrade() << std::endl
		<< "Status: " << status << std::endl;
	form.appendToStream(os);
	return os;
}
