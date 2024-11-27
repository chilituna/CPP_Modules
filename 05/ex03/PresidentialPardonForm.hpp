/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:10:29 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/20 11:30:37 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRSEIDENTALPARDONFORM_HPP
# define PRSEIDENTALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		//orthodox canonical form
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		const PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		//getters
		const std::string& getTarget()const ;

		//member functions
		void execute()const;

		//operator overloading addon
		void appendToStream(std::ostream& os) const;

	private:
		std::string _target;
};

#endif //PRSEIDENTALPARDONFORM_HPP