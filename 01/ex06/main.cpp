/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:57:55 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/01 21:02:34 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Wrong input. Usage: " << argv[0] << " <level of complaint>" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
