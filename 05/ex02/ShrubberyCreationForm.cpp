/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:27:09 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:43:36 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.


// ORTHODOX CANONICAL FORM

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery creation", 145, 137)
{
	std::cout << "---ShrubberyCreationForm default constructor called---" << std::endl;
	this->_target = "unnamed";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery creation", 145, 137)
{
	std::cout << "---ShrubberyCreationForm constructor called---" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("Shrubbery creation", 145, 137)
{
	std::cout << "---ShrubberyCreationForm copy constructor called---" << std::endl;
	this->_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "---ShrubberyCreationForm copy assignment constructor called---" << std::endl;
	if (this != &other)
		this->_target = other.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "---ShrubberyCreationForm destructor called---" << std::endl;
}


// GETTERS

const std::string& ShrubberyCreationForm::getTarget(void) const
{
 return this->_target;
}


// EXCEPTION

const char* ShrubberyCreationForm::ErrorFileException::what(void) const throw()
{
	return "Error opening file";
}


// MEMBER FUNCTIONS

void ShrubberyCreationForm::execute(void) const
{
	std::string filename = _target + "_shrubbery";

	std::ofstream ofs(filename.c_str(), std::ios::app); // open the file in append mode

	if (ofs.is_open())
	{
		ofs << "                    |            " << std::endl;
		ofs << "          v .   ._, |_  .,       " << std::endl;
		ofs << "       `-._\\/  .  \\ /    |/_     " << std::endl;
		ofs << "           \\  _\\, y | \\//       " << std::endl;
		ofs << "     _\\_.___\\, \\/ -.\\||        " << std::endl;
		ofs << "       `7-,--.`._||  / / ,       " << std::endl;
		ofs << "       /'     `-. `./ / |/_.'    " << std::endl;
		ofs << "                 |    |//        " << std::endl;
		ofs << "                 |_    /         " << std::endl;
		ofs << "                 |-   |          " << std::endl;
		ofs << "                 |   =|          " << std::endl;
		ofs << "                 |    |          " << std::endl;
		ofs << "----------------/ ,  . \\--------._" << std::endl;
		ofs << std::endl;
		std::cout << "Shrubbery created at " << _target << "_shrubbery." << std::endl;
	}
	else
		throw ErrorFileException();
	ofs.close();
}