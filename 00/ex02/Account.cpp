/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:14:58 by aarponen          #+#    #+#             */
/*   Updated: 2024/06/25 16:29:42 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

// initialize static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// getter functions
int Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

// constructor
Account::Account(int initial_deposit)
{

	Account::_accountIndex = Account::getNbAccounts();
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

// destructor
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" << std::endl;
}

// static functions
void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";deposits:" << Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex
		<< ";p_amount:" << Account::_amount;
	std::cout << ";deposit:" << deposit;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_nbDeposits++;
	std::cout << ";amount:" << Account::_amount
		<< ";nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex
		<< ";p_amount:" << Account::_amount;
	if (Account::_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_nbWithdrawals++;
	std::cout << ";amount:" << Account::_amount
		<< ";nb_withdrawals:" << Account::_nbWithdrawals<< std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return(Account::_amount);
}

// 1. get the current time as a std::time_t object, which represents the number of seconds since the epoch (usually January 1, 1970).
// 2. convert the std::time_t object to a std::tm structure representing the local time.
// The std::tm structure contains various fields like year, month, day, hour, minute, and second.
void Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);
	std::cout << "[" << now->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << now->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << now->tm_mday
		<< "_" << std::setw(2) << std::setfill('0') << now->tm_hour
		<< std::setw(2) << std::setfill('0') << now->tm_min
		<< std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}
