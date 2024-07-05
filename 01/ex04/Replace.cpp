/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:59:43 by aarponen          #+#    #+#             */
/*   Updated: 2024/07/05 12:09:36 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

// constructor
Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2)
	: filename(filename), s1(s1), s2(s2) {}

// file needs to be opened before reading and writing:
// ifstream opens the file for reading
// read the entire file into a string stream buffer using rdbuf()
// close the file
// return the buffer as a string
std::string Replace::readFile() const
{
	std::ifstream read_file(filename.c_str());
	if (!read_file.is_open())
	{
		throw std::runtime_error(RED + std::string("Error opening the file") + RESET);
	}
	std::stringstream buffer;
	buffer << read_file.rdbuf();
	read_file.close();
	return buffer.str();

}
// write the buffer to the file
void Replace::writeFile(const std::string &buffer) const
{
	std::string replace = filename + ".replace";
	std::ofstream write_file(replace.c_str());
	if (!write_file.is_open())
	{
		throw std::runtime_error(RED + std::string("Error opening the file") + RESET);
	}
	write_file << buffer;
	write_file.close();
}
// replace the string s1 with s2 in the file:
// read the file into a buffer
// find the string s1 in the buffer: position is returned
// If none found, find() returns npos
// replace s1 with s2: erase s1 and insert s2
void Replace::replaceString()
{
	if (s1.empty())
	{
		throw std::runtime_error(RED + std::string("Cannot replace empty string") + RESET);
	}
	std::string buffer = readFile();
	size_t pos = 0;
	while ((pos = buffer.find(s1, pos)) != std::string::npos)
	{
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos += s2.length();
	}
	writeFile(buffer);
}


