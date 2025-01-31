/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:36:11 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/06 17:44:16 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

#define NUMBER_QUANTITY 10000

int main()
{
	// Test from Subject
	std::cout << "TEST 1" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	// Test using range iterator
	std::cout << "TEST 2" << std::endl;

	std::srand(std::time(0));
	Span large = Span(NUMBER_QUANTITY);

	std::vector<int> numbers;
	for (int i = 0; i < NUMBER_QUANTITY; ++i)
	{
		int value = std::rand() % INT_MAX;
		numbers.push_back(value);
	}
	large.addMany(numbers.begin(), numbers.end());
	std::cout << "Shortest Span: " << large.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << large.longestSpan() << std::endl;
	std::cout << std::endl;

	// Testing container full ERROR
	std::cout << "TEST 3" << std::endl;

	try
	{
		large.addNumber(7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	// Testing not enough numbers ERROR
	std::cout << "TEST 4" << std::endl;

	Span small(5);
	try
	{
		small.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	small.addNumber(10);
	try
	{
		small.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
