/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:16:47 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:30:52 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <string>
# include <cstdlib> // For srand()
# include <ctime>   // For time()
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		//orthodox canonical form
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		//getters
		const std::string& getTarget()const;

		//member functions
		void execute() const;

		//operator overloading addon
		void appendToStream(std::ostream& os) const;

	private:
		std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP
