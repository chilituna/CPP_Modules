/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:42:15 by aarponen          #+#    #+#             */
/*   Updated: 2024/08/31 16:55:41 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap(void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// getters for testing
		unsigned int	getHitpoints();
		unsigned int	getEnergy();
		std::string		getName();

	private:
		std::string		_name; // passed as parameter to the constructor
		unsigned int	_hit_points; // present the health of the ClapTrap
		unsigned int	_energy_points; // attacking and repairing cost 1 energy point each
		unsigned int	_attack_damage; // When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
};

#endif
