/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:57:57 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/06 17:39:47 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


// ORTHODOX CANOCICAL FORM

Span::Span(unsigned int N): _size(N)
{}

Span::Span(const Span& other): _size(other._size), _numbers(other._numbers)
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{}


// MEMBER FUNCTIONS

void Span::addNumber(int value)
{
	if (this->_numbers.size() >= this->_size)
		throw ConteinerFullException();
	this->_numbers.push_back(value);
}

int	Span::shortestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw TooFewValuesException();

	int shortest_span = INT_MAX;
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());
	for (unsigned int i = 0; i < this->_size - 1; ++i)
		shortest_span = std::min(shortest_span, sorted[i + 1] - sorted[i]);
	return shortest_span;
}

int	Span::longestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw TooFewValuesException();

	int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return max - min;
}

void Span::addMany(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t rangeSize = std::distance(begin, end);
	if (rangeSize > this->_size - this->_numbers.size())
		throw ConteinerFullException();
	this->_numbers.insert(this->_numbers.end(), begin, end);
}

unsigned int Span::getSize(void)
{
	return this->_size;
}