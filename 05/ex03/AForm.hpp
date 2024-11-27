/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:18:15 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:22:48 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		//orthodox canonical form
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(const AForm& other);
		virtual ~AForm();

		//member functions
		void beSigned(Bureaucrat& bureaucrat);
		void beExecuted(const Bureaucrat& executor) const;
		virtual void execute() const = 0;

		//getters
		const std::string& getName() const;
		bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecGrade() const;

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
		class FormNotSignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		//to get the target from derived classes:
		virtual void appendToStream(std::ostream& os) const = 0;

	private:
		AForm();
		AForm& operator=(const AForm& other);

		const std::string _name;
		const int	_sign_grade;
		const int	_exec_grade;
		bool	_is_signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);


#endif //FORM_HPP