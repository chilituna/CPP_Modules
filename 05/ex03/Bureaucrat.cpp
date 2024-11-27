/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:56:09 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/17 18:43:05 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//CONSTRUCTION AND DESCTRUCTION (Orthodox Canonical Form)
// Default constructor omitted intentionally to enforce initialization with name and grade


Bureaucrat::Bureaucrat(int grade, const std::string& name): _name(name), _grade(grade)
{
	std::cout << "---Bureaucrat constructor called.---" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "---Bureaucrat copy constructor called.---" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "---Bureaucrat copy assignment constructor called.---" << std::endl;
	if (this != &other)
		 // Only update grade; name is constant and should not be reassigned
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "---Bureaucrat destructer called.---" << std::endl;
}


//GETTERS

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}


//GRADE MANIPULATION

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	_grade++;

}


// SIGN FORM

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn’t sign "  << form.getName() << " because " << e.what() << std::endl;
	}
}


// EXECITE FORM

void Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		form.beExecuted(*this);
		std::cout << _name << " executed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn’t execute "  << form.getName() << " because " << e.what() << std::endl;
	}
}


//EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high! (max 1, min 150)\n");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low! (max 1, min 150)\n");
}


//OPERATOR OVERLOADING

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
    return os;
}

