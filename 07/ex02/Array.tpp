/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:08:37 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/01 12:46:11 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

// ORTHODOX CANONICAL FORM

template <typename T>
Array<T>::Array() : _ptr(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int size) : _ptr(new T[size]()), _size(size)
{}

template <typename T>
Array<T>::Array(const Array<T>& other) : _ptr(NULL), _size(other._size)
{
	if (this->_size > 0)
	{
		this->_ptr = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; ++i)
		{
			this->_ptr[i] = other._ptr[i];
		}
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] this->_ptr;

		this->_size = other._size;
		this->_ptr = new T[this->_size];

		for (unsigned int i = 0; i < this->_size; ++i)
		{
			this->_ptr[i] = other._ptr[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _ptr;
}

// MEMBER FUNCTIONS

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

// OPERAOTR OVERLOADING

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (_ptr == NULL || index >= this->_size)
		throw OutOfBoundsException();
	return this->_ptr[index];
}

#endif //ARRAY_TPP