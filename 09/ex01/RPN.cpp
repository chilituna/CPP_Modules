/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:40:46 by aarponen          #+#    #+#             */
/*   Updated: 2025/02/03 11:47:27 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//ORTHODOX CANONICAL FORM

Rpn::Rpn()
{}

Rpn::~Rpn()
{}

Rpn::Rpn(const Rpn& other)
{
	(void)other;
}

Rpn& Rpn::operator=(const Rpn& other)
{
	(void)other;
	return *this;
}


// MEMBER FUNCTIONS

// Load numbers to the stack: separating by space and validate
double Rpn::calculate(std::string input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token.size() == 1)
		{
			if (token[0] >= '0' && token[0] <= '9')
				this->numbers.push(token[0] - '0');
			else
				try
				{
					this->processOperator(token[0]);
				}
				catch(const std::exception& e)
				{
					 throw;
				}
		}
		else
			throw std::invalid_argument("Invalid input. Allowed numbers: 0-9. Allowed operands: + - / *");
	}
	if (this->numbers.size() != 1)
		throw std::logic_error("Invalid RPN expression.");
	return numbers.top();

}

void Rpn::processOperator(char op)
{
	if (this->numbers.size() < 2)
		throw std::logic_error("Not enough operands.");

	double n2 = this->numbers.top();
	this->numbers.pop();
	double n1 = this->numbers.top();
	this->numbers.pop();

	double result;
	switch(op)
	{
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			if (n2 == 0)
				throw std::domain_error("Division by 0");
			result = n1 / n2;
			break;
		default:
			throw std::invalid_argument("Invalid operator.");
	}

	this->numbers.push(result);
}
