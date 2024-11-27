/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:20:10 by aarponen          #+#    #+#             */
/*   Updated: 2024/11/24 14:22:00 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

int	main(void)
{
	Data	data;
	data.i = 42;
	data.str = "Howdy!";
	Data*	dataPtr = &data;

	std::cout << "Original Data: \n";
	std::cout << "i: " << dataPtr->i << std::endl;
	std::cout << "str: " << dataPtr->str << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(dataPtr);
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << std::endl;

	Data*	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data: \n";
	std::cout << "i: " << deserialized->i << std::endl;
	std::cout << "str: " << deserialized->str << std::endl;
	std::cout << std::endl;

	// Verify the pointers match
	std::cout << dataPtr << std::endl;
	std::cout << deserialized << std::endl;;

    if (dataPtr == deserialized) {
        std::cout << "Serialization and Deserialization succeeded!" << std::endl;
    } else {
        std::cout << "Serialization and Deserialization failed!" << std::endl;
    }


}