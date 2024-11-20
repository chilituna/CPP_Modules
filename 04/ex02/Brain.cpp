/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:49:33 by aarponen          #+#    #+#             */
/*   Updated: 2024/09/15 17:00:20 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created\n";
}

Brain::Brain(const Brain& copy)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; 1 < 100; i++)
			ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain copy assignment operator called\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed\n";
}

void	Brain::setIdeas(std::string idea, int i)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
}

std::string Brain::getIdeas(int i) const
{
	if (i >= 0 && i < 100)
		return (this->ideas[i]);
	return "Wrong index";
}