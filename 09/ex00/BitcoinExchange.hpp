/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:01:44 by aarponen          #+#    #+#             */
/*   Updated: 2025/01/13 13:44:33 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <cctype>

class BitcoinExchange
{
	public:
		// orthodox canonical form
		BitcoinExchange();
		~BitcoinExchange();

		// member functions to read database and input file
		void loadDatabase(const std::string& file);
		void processInput(const std::string& file);

	private:
		// orthodox canonical form
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		// member functions to validate and calclulate data
		bool validDate(const std::string& date) const;
		float calculateValue(const std::string& date, float value) const;

		// container to store values
		std::map<std::string, float> exchangeRates;
};

#endif //BITCOINEXCHANGE_HPP