/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:16:24 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/01 13:33:41 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#define RED "\033[31m"
#define RESET "\033[0m"

class Replace
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;

		std::string readFile () const;
		void writeFile(const std::string &buffer) const;

	public:
		Replace(const std::string &filename, const std::string &s1, const std::string &s2);
		void replaceString();

};

#endif
