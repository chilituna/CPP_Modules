/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:40:54 by aarponen          #+#    #+#             */
/*   Updated: 2025/01/18 16:38:12 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <set>
# include <string>
# include <stdexcept>
# include <sstream>
# include <iostream>

class Rpn
{
	public:
		// orthodox canonical form
		Rpn();
		~Rpn();

		// member functions
		double calculate(std::string input);

	private:
		// orthodox canonical form
		Rpn(const Rpn& other);
		Rpn& operator=(const Rpn& other);

		// container
		std::stack<double> numbers;

		// member functions
		void processOperator(char op);

};

#endif //RNP_HPP