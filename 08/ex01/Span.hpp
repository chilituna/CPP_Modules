/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:37:18 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/06 17:42:12 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <exception>
# include <string>
# include <algorithm>
# include <climits>

class Span
{
	public:
		// Orthodox Canonical Form
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		// Member Functions
		void addNumber(int value);
		int	shortestSpan(void) const;
		int	longestSpan(void) const;
		void addMany(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		// Exceptions
		class ConteinerFullException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Container full!";
				}
		};

		class TooFewValuesException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Container does not have enough values to count span.";
				}
		};

		// Getters
		unsigned int getSize(void);

	private:
		Span();
		unsigned int _size;
		std::vector<int> _numbers;


};

#endif //SPAN_HPP