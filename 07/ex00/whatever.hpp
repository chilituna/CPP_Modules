/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:46:28 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/30 16:05:01 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T& min(T& a, T& b)
{
	return (a < b) ? a : b;
}

template<typename T>
T max(T& a, T& b)
{
	return (a > b) ? a :b;
}

#endif //WHATEVER_HPP