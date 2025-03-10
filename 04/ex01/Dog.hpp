/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:27:24 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 17:03:04 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& copy);
		Dog& operator=(const Dog &copy);
		~Dog(void);

		void makeSound(void) const;
		void setBrainIdea(std::string idea, int i);
		std::string getBrainIdea(int i) const;

	private:
		Brain*	_brain;
};

#endif
