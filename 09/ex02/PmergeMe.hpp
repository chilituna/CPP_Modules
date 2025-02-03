/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:40:46 by aarponen          #+#    #+#             */
/*   Updated: 2025/02/02 17:01:34 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// PURPOSE:
// Sort the container using the merge-insert sort algorithm (Ford-Johnson algorithm).
// (source: Art Of Computer Programming, Vol.3. Merge Insertion, Page 184.)
// IMPLEMENTATION:
// - Works with std::vector and std::deque.
// - The container must have at least one element.
// - The container must have positive integers.

# include <vector>
# include <deque>
# include <sstream>
# include <climits>
# include <iostream>
# include <algorithm>
# include <utility>

const int NOT_SET = -1;

template <typename Container>
class PmergeMe
{
	public:
		// orthodox canonical form
		PmergeMe();
		~PmergeMe();

		// member functions
		Container sortContainer(Container& sequence);

	private:
		// orthodox canonical form
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
};

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP