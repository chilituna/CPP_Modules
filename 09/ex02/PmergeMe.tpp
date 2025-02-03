/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:19:09 by aarponen          #+#    #+#             */
/*   Updated: 2025/02/02 16:59:35 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

// --- ORTHODOX CANONICAL FORM ---

template <typename Container>
PmergeMe<Container>::PmergeMe()
{}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other)
{
	(void)other;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& other)
{
	(void)other;
	return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{}

// --- HELPER FUNCTIONS ---

// Generate Jacobsthal sequence:
// With an exceptions that if the last element is bigger than n, it should be the index of the last element.
std::vector<size_t> generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> sequence;

	sequence.push_back(0); // J(0)
	sequence.push_back(1); // J(1)

	for (size_t i = 2;; ++i)
	{
		size_t next = sequence[i - 1] + 2 * sequence[i - 2];
		if (next >=  n)
		{
			sequence.push_back(n);
			break;
		}
		sequence.push_back(next);
	}

	return sequence;
}

// Binary insertion:
// - return the index of the inserted value.
template <typename Container>
int binaryInsert(Container& sequence, int end, int value)
{
	int left = 0;
	int right = end;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (sequence[mid] == value)
		{
			sequence.insert(sequence.begin() + mid, value);
			return mid;
		}
		else if (sequence[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	sequence.insert(sequence.begin() + left, value);

	return left;
}

// --- HELPER FUNCTIONS AND STRUCT FOR SORTING ---

struct Pair
	{
		int a; // larger
		int b; // smaller
		Pair() : a(NOT_SET), b(NOT_SET) {}
	};

// 1. Divide sequence into pairs:
// - if the sequence has an odd number of elements, leave it out and store for later.
template <typename Container>
void divideIntoPairs(std::vector<Pair>& pairs, Container& sequence, int& odd)
{
	pairs.resize(sequence.size() / 2);
	for (size_t i = 0; i < sequence.size(); i += 2)
	{
		if (i + 1 < sequence.size())
		{
			pairs[i/2].a = sequence[i];
			pairs[i/2].b = sequence[i + 1];
		}
		else
			odd = sequence[i];
	}
}

// 2. Sort each pair:
// - higher value first
// - while sorting, determine max_value for both bigger and smaller values.
void sortPairs(std::vector<Pair>& pairs, int& max_value_a, int& max_value_b)
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].a < pairs[i].b)
			std::swap(pairs[i].a, pairs[i].b);
		if (pairs[i].b > max_value_b)
			max_value_b = pairs[i].b;
		if (pairs[i].a > max_value_a)
			max_value_a = pairs[i].a;
	}
}

// 2.a Create lookup tables for the larger and smaller values:
// - The value of the pair is used as the index to find the pair value.
// - for duplicate values, store the smallest index.
void createLookupTables(std::vector<Pair>& pairs, std::vector<int>& lookup_bigger, std::vector<int>& lookup_smaller)
{
	for (size_t i = 0; i < pairs.size(); ++i)
		{
			if (lookup_bigger[pairs[i].b] == NOT_SET)
			{
				lookup_bigger[pairs[i].b] = pairs[i].a;
				lookup_smaller[pairs[i].a] = pairs[i].b;
			}
			else if (pairs[i].a < lookup_bigger[pairs[i].b])
				lookup_bigger[pairs[i].b] = pairs[i].a;
			if (lookup_smaller[pairs[i].a] == NOT_SET)
				lookup_smaller[pairs[i].a] = pairs[i].b;
		}
}

// 4. Insert the pending values to the sorted using binary insertion with Jacobsthal sequence:
// - add the pending values to the sorted sequence as follows:
// -- insert the first pending value in the front of the sorted sequence, as we know it is the lowest value.
// --- update the index lookup table: all the excisting values (non NOT_SET values) +1 .
// -- form groups that follow the difference between sequential elements in Jacobsthal numbers, starting after the third.
// -- insert the groups in reverse order to the sorted sequence.
// --- get the original pair value from the lookup table.
// --- get the index of the pair value from the lookup table.
// --- perform binary insertion to the sorted subsequence.
// --- update the index lookup table: all the excisting values after insertion poin (non NOT_SET values) +1.
// -- if there was an odd element, insert it last.
template <typename Container>
void insertion(Container& sorted, Container& pending, const std::vector<int>& lookup_bigger, std::vector<int>& lookup_index, int odd)
{

	// Insert the first pending value in the front of the sorted sequence and update the index lookup table.
	sorted.insert(sorted.begin(), pending[0]);
	for (size_t i = 0; i < sorted.size(); ++i)
	{
		if (lookup_index[sorted[i]] != NOT_SET)
			++lookup_index[sorted[i]];
	}

	// Create the insertion order for the pending values.
	std::vector<size_t> insertion_order;
	std::vector<size_t> jacobsthal_seq = generateJacobsthalSequence(pending.size());
	for (size_t i = 3; i < jacobsthal_seq.size(); ++i)
	{
		size_t group_size = jacobsthal_seq[i] - jacobsthal_seq[i - 1];
		size_t index = jacobsthal_seq[i] - 1;
		for (size_t j = 0; j < group_size; ++j)
		{
			insertion_order.push_back(index);
			--index;
		}
	}

	// Insert the pending values to the sorted sequence according to the insertion order.
	// - update the index lookup table.
	// - if there was an odd element, insert it last.
	for (size_t i = 1; i < pending.size(); ++i)
	{
		int value = pending[insertion_order[i - 1]];
		int pair_value = lookup_bigger[value];
		int pair_index;
		pair_index = lookup_index[pair_value];
		int end = binaryInsert(sorted, pair_index, value);
		for (size_t j = end; j < sorted.size(); ++j)
		{
			if (lookup_index[sorted[j]] != NOT_SET)
				++lookup_index[sorted[j]];
		}
	}
	if (odd != NOT_SET)
		binaryInsert(sorted, sorted.size() - 1, odd);
}


// --- MEMBER FUNCTIONS ---

// SORTING WITH CONTAINER
template <typename Container>
Container PmergeMe<Container>::sortContainer(Container& sequence)
{

	// 0. Base case: If the container is empty or has only one element, return.
	if (sequence.size() <= 1)
		return sequence;

	// 1. Divide into pairs and store the possible odd element for later.
	int odd = NOT_SET;
	std::vector<Pair> pairs;
	divideIntoPairs(pairs, sequence, odd);

	// 2. Sort each pair and determine the max value of the larger values.
	int max_value_a = 0;
	int max_value_b = 0;
	sortPairs(pairs, max_value_a, max_value_b);

	// 2.a Create the lookup tables for the larger and smaller values:
	std::vector<int> lookup_bigger(max_value_b + 1, NOT_SET);
	std::vector<int> lookup_smaller(max_value_a + 1, NOT_SET);
	createLookupTables(pairs, lookup_bigger, lookup_smaller);

	// 3. Divide into sorted and pending and recursively sort the first values of the pairs creating a sorted sequence
	//  in ascending order, using the merge-insertion sort.
	// 3a. Create the sorted sequence and call the function recursively.
	Container sorted;
	for (size_t i = 0; i < pairs.size(); ++i)
		sorted.push_back(pairs[i].a);
	sorted = sortContainer(sorted);

	// 3b. Create the pending sequence using the lookup table to make sure the values are aligned with the sorted sequence.
	Container pending;
	for (size_t i = 0; i < sorted.size(); ++i)
		pending.push_back(lookup_smaller[sorted[i]]);

	// 3c. Create the lookup table with the index of the largest values of the pairs in the sorted sequence.
	// - for duplicates, keep the smallest index
	std::vector<int> lookup_index(max_value_a + 1, NOT_SET);
	for (size_t i = 0; i < sorted.size(); ++i)
	{
		if (lookup_index[sorted[i]] == NOT_SET)
			lookup_index[sorted[i]] = i;
	}

	// 4. Insert the second values using binary insertion with Jacobsthal seqeuence.
	insertion(sorted, pending, lookup_bigger, lookup_index, odd);

	return sorted;
}

#endif // PMERGEME_TPP
