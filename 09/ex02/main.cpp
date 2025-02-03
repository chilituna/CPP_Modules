/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:40:40 by aarponen          #+#    #+#             */
/*   Updated: 2025/02/03 17:05:22 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

template <typename Container>
bool isSorted(const Container& numbers)
{
	for (size_t i = 1; i < numbers.size(); ++i)
	{
		if (numbers[i - 1] > numbers[i])
			return false;
	}
	return true;
}

bool convertToInt(const std::string& token, int& value)
{
	std::stringstream ss(token);

	ss >> value;

	return !ss.fail() && ss.eof() && value >= 0;
}

std::vector<int> parseInput(int argc, char* argv[])
{
	std::vector<int> numbers;
	if (argc == 2)
	{
		std::istringstream iss(argv[1]);
		std::string token;
		while (iss >> token)
		{
			int value;
			if (!convertToInt(token, value))
				throw std::invalid_argument("Incorrect input: " + token + ". Only positive integers allowed.");
			numbers.push_back(value);
		}
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string token = argv[i];
			int value;
			if (!convertToInt(token, value))
				throw std::invalid_argument("Incorrect input: " + token + ". Only positive integers allowed.");
			numbers.push_back(value);
		}
	}
	//If the container is empty or has only one element, return.
	if (numbers.size() <= 1)
		throw std::invalid_argument("The container is empty or has only one element. Hard to sort.");

	return numbers;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Invalid input. Usage: ./PmergeMe <positive integer sequence> " << std::endl;
		return 1;
	}

	std::vector<int> numbers = parseInput(argc, argv);
	std::deque<int> numbers_deque(numbers.begin(), numbers.end());

	try
	{
		// SORTING WIT VECTOR
		PmergeMe<std::vector<int> > sort_vector;

		std::cout << "Before: ";
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		clock_t start_time = clock();
		std::vector<int> sorted_vector = sort_vector.sortContainer(numbers);
		clock_t end_time = clock();

		if (!isSorted<std::vector<int> >(sorted_vector))
			throw std::runtime_error("Vector is not sorted.");

		std::cout << "After:  ";
		for (std::vector<int>::iterator it = sorted_vector.begin(); it != sorted_vector.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << std::fixed << std::setprecision(2);
		double duration = double(end_time - start_time) / (CLOCKS_PER_SEC / 1000000.000);
		std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector: " << duration << " us." << std::endl;

		// SORTING WITH DEQUE
		PmergeMe<std::deque<int> > sort_deque;

		start_time = clock();
		std::deque<int> sorted_deque = sort_deque.sortContainer(numbers_deque);
		end_time = clock();

		if (!isSorted<std::deque<int> >(sorted_deque))
			throw std::runtime_error("Deque is not sorted.");

		duration = double(end_time - start_time) / (CLOCKS_PER_SEC / 1000000.000);
		std::cout << "Time to process a range of " << numbers.size() << " elements with std::deque: " << duration << " us." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}