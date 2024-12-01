/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:53:47 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/30 15:06:07 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_FUNCTIONS_HPP
# define TEST_FUNCTIONS_HPP

#include <cctype>
#include <string>


template <typename T>
void increase(T& value)
{
	value++;
}

void to_uppercase(std::string& str)
{
	for (size_t i  = 0; i < str.size(); ++i)
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
}

#endif // TEST_FUNCTIONS_HPP

