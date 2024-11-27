/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:18:04 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:41:10 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// ORTHODOX CANONICAL FORM
// Default constructor omitted intentionally to enforce initialization with name and grades
// Copy assignment operator is also omitted, as copying constant values is not meaningful in this context.

Form::Form(std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(false)
{
	std::cout << "---Form constructor called.---" << std::endl;
	if (_sign_grade < 1 or _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 or _exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade), _is_signed(false)
{
	std::cout << "---Copy Form constructor called.---" << std::endl;
}

Form::~Form()
{
	std::cout << "---Form destructor called.---" << std::endl;
}


//GETTERS

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSignedStatus() const
{
	return _is_signed;
}

int Form::getSignGrade() const
{
	return _sign_grade;
}

int Form::getExecGrade() const
{
	return _exec_grade;
}


// MEMBER FUNCTIONS

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooLowException();
	this->_is_signed = true;
}


// EXCEPTION CLASSES


const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}


// OPERATOR OVERLOADING

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	std::string status = form.getSignedStatus() ? "signed" : "not signed";

	os << "Form: " << form.getName() << std::endl
		<< "Grade required to sign: " << form.getSignGrade() << std::endl
		<< "Grade required to execute: " << form.getExecGrade() << std::endl
		<< "Status: " << status << std::endl;
	return os;
}

