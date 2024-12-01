/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:00:13 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/01 12:22:10 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>

template <typename T, typename Func>
void iter(T* arr, size_t len, Func func)
{
	for(size_t i = 0; i < len; ++i)
		func(arr[i]);
}

#endif //ITER_HPP