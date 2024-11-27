/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:15:18 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:08:30 by aarponen         ###   ########.fr       */
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

		//member functions
		void execute() const;

		//exceptions
		class ErrorFileException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		//getters
		const std::string& getTarget()const ;

	private:
		std::string _target;
};

#endif // SHRUBBERYCREATIONFORM_HPP