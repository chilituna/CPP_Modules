/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:56:03 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 10:28:49 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		//Orthodox canonical form
		Bureaucrat(int grade, const std::string& name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//Getters
		const std::string& getName() const;
		int			getGrade() const;

		//Grade change
		void	incrementGrade();
		void	decrementGrade();

		//Sign form
		void	signForm(Form& form);

		//Exception classes
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		Bureaucrat();

		const std::string	_name;
		int					_grade;
};

//Operator overloading
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureacrat);

#endif  // BUREAUCRAT_HPP
