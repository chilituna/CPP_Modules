/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:15:18 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:29:58 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		//orthodox canonical form
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		//getters
		const std::string& getTarget()const;

		//member functions
		void execute() const;

		//exceptions
		class ErrorFileException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		//operator overloading addon
		void appendToStream(std::ostream& os) const;

	private:
		std::string _target;
};

#endif // SHRUBBERYCREATIONFORM_HPP