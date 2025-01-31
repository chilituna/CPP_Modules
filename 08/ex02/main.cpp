/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:58:25 by aarponen          #+#    #+#             */
/*   Updated: 2024/12/11 14:08:12 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	// Basic test from subject
	std::cout << "TEST 1" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::list<int> compare;
	compare.push_back(5);
	compare.push_back(17);
	std::cout << compare.back() << std::endl;
	compare.pop_back();
	std::cout << compare.size() << std::endl;
	compare.push_back(3);
	compare.push_back(5);
	compare.push_back(737);
	compare.push_back(0);
	std::list<int>::iterator itl = compare.begin();
	std::list<int>::iterator itel = compare.end();
	++itl;
	--itl;
	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> sl(compare);
	std::cout << std::endl;

	// Testing reverse iterator with string container
	std::cout << "TEST 2" << std::endl;
	MutantStack<std::string> string_stack;
	string_stack.push("a");
	string_stack.push("d");
	string_stack.pop();
	string_stack.push("b");
	string_stack.push("c");
	MutantStack<std::string>::reverse_iterator iter = string_stack.rbegin();
	MutantStack<std::string>::reverse_iterator itere = string_stack.rend();
	while (iter != itere)
	{
		std::cout << *iter << std::endl;
		++iter;
	}




	return 0;
}