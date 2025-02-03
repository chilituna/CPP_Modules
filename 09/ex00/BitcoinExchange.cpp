/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:58:22 by aarponen          #+#    #+#             */
/*   Updated: 2025/02/03 11:36:01 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//ORTHODOX CANONICAL FORM

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		exchangeRates = other.exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}


// HELPER FUNCTIONS

// check if space
bool isSpace(char c)
{
	return std::isspace(static_cast<unsigned char>(c));
}

// check if leap year
bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


// METHODS

// convert string to float and make sure it is within range 0-1000
float stringToFloat(const std::string& str)
{
	std::stringstream ss(str);
	float value;
	ss >> value;
	if (ss.fail())
		throw std::invalid_argument("Error: Invalid float string: " + str);
	if (value < 0)
		throw std::out_of_range("Error: not a positive number.");
	if (value > 1000)
		throw std::out_of_range("Error: too large a number.");
	return value;
}

// calculate result based on the exchange rate:
// create an iterator and use lower_bound to return:
// 1. the first element in the map where the key is greater than or equal to date, if such an element exists.
// 2. The end of the map (exchangeRates.end()) if no such element is found.
float BitcoinExchange::calculateValue(const std::string& date, float value) const
{
	std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
	if (it == exchangeRates.end() || it->first != date)
	{
		if (it == exchangeRates.begin())
			throw std::invalid_argument("Error: No data found for given date: " + date);
		it--;
	}
	return value * it->second;
}


// Check date: make sure format is correct and that the year, month and day are within range.
// Extract data with the extraction operator (>>) and check for correct format.
bool BitcoinExchange::validDate(const std::string& date) const
{
	int year, month, day;
	char dash1, dash2;

	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

// Loading the CSV file into the std::map.
// separate date (before comma) and convert the rest to float (rate)
// save only valid lines
void BitcoinExchange::loadDatabase(const std::string& file)
{
	std::string line;
	std::string date;
	float rate;

	std::ifstream database(file.c_str());
	if (!database.is_open())
		throw std::runtime_error("Error: could not open database file.");

	while (std::getline(database, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ',') && iss >> rate)
			exchangeRates[date] = rate;
	}
}


// Parsing and validating the input file:
// Trim any white space using remove_if(packs any white space in the end) and erase(does the actual erasing)
// 1. convert value to float
// 2. validate date
// 3. calculate value per rate
// 4. catch any errors and execptions per line
void BitcoinExchange::processInput(const std::string& file)
{
	std::string line;
	std::string date;
	std::string value_string;
	float	value;
	float	calculated_value;

	std::ifstream input_file(file.c_str());
	if (!input_file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::getline(input_file, line); // skip header
	while (std::getline(input_file, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, '|') && std::getline(iss, value_string))
		{
			date.erase(std::remove_if(date.begin(), date.end(), isSpace), date.end());
			value_string.erase(std::remove_if(value_string.begin(), value_string.end(), isSpace), value_string.end());
			try
			{
				value = stringToFloat(value_string);
				if (!validDate(date))
					throw std::invalid_argument("Error: incorrect date format: " + date);
				calculated_value = calculateValue(date, value);
				std::cout << date << " => " << value << " = " << calculated_value << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}

