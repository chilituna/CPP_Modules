/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:20:57 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/11 14:03:20 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <stack>
#include <iostream>
#include <ctime>

#define CONTAINER_SIZE 20
#define MAX_VALUE 30

int main(void)
{

	srand(time(NULL));
	int	searched_value = 7;

	// TEST WITH LIST:
	std::cout << std::endl << "-- TEST 1 with LIST --" << std::endl ;
	std::list<int> numberList;

    for (int i = 0; i < CONTAINER_SIZE; i++)
    {
        const int value = rand() % MAX_VALUE;
		numberList.push_back(value);
	}
	try
	{
		std::list<int>::iterator found = easyfind(numberList, searched_value);
		std::cout << *found << " - Value found at address: " << &(*found) << std::endl;
		std::cout << "LIST:" << std::endl;
		for (std::list<int>::iterator it = numberList.begin(); it != numberList.end(); ++it)
		{
			std::cout << *it;
			if (*it == searched_value)
				std::cout << " - " << &(*it);
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "LIST:" << std::endl;
		for (std::list<int>::iterator it = numberList.begin(); it != numberList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	// TEST WITH VECTOR:
	std::cout << std::endl << "-- TEST 2 with VECTOR --" << std::endl ;
	std::vector<int> numberVector;

    for (int i = 0; i < CONTAINER_SIZE; i++)
    {
        const int value = rand() % MAX_VALUE;
		numberVector.push_back(value);
	}
	try
	{
		std::vector<int>::iterator found = easyfind(numberVector, searched_value);
		std::cout << *found << " - Value found at address: " << &(*found) << std::endl;
		std::cout << "VECTOR:" << std::endl;
		for (std::vector<int>::iterator it = numberVector.begin(); it != numberVector.end(); ++it)
		{
			std::cout << *it;
			if (*it == searched_value)
				std::cout << " - " << &(*it);
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "VECTOR:" << std::endl;
		for (std::vector<int>::iterator it = numberVector.begin(); it != numberVector.end(); ++it)
			std::cout << *it << std::endl;
	}
}