/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:14:15 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/01 12:41:40 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
	public:
		//orthodox canonical format
		Array();
		Array(unsigned int size);
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>& other);
		~Array();

		//member functions
		unsigned int size() const;

		//subscript operator
		T& operator[](unsigned int index);

		//exceptions
		class OutOfBoundsException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					 return "Index is out of bounds!";
				}
		};


	private:
		T* _ptr;
		unsigned int _size;

};

# include "Array.tpp"

#endif // ARRAY_HPP