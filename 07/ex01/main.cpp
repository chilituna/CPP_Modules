/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:44:08 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/30 15:09:59 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "test_functions.hpp"
#include <iostream>
#include <string>

int main(void)
{
	int arr[] = {1, 3, 5, 10};
	::iter(arr, 4, ::increase<int>);
	for (int i = 0; i < 4; ++i)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;

	char arr1[] = {'a', 'b', 'z'};
	::iter(arr1, 3, ::increase<char>);
	for (int i = 0; i < 3; ++i)
		std::cout << arr1[i] << std::endl;
	std::cout << std::endl;

	std::string arr2[] = {"hello", "there", "And", "herE"};
	::iter(arr2, 4, to_uppercase);
	for (int i = 0; i < 4; ++i)
		std::cout << arr2[i] << std::endl;
	std::cout << std::endl;

}