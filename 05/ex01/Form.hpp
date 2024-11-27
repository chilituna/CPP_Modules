/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:18:15 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 10:27:30 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		//orthodox canonical form
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& other);
		~Form();

		void beSigned(Bureaucrat& bureaucrat);

		//getters
		const std::string& getName() const;
		bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecGrade() const;

		//exception classes
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
		Form();
		Form& operator=(const Form& other);

		const std::string _name;
		const int	_sign_grade;
		const int	_exec_grade;
		bool	_is_signed;
};

// operator overloading
std::ostream& operator<<(std::ostream& os, const Form& form);


#endif //FORM_HPP