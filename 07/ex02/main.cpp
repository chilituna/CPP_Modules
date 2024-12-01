#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	// TEST 1:
	// Create an instance of Array class with MAX_VAL (750) elements.
	// Create another int arr, and save same random values to both for comparing.
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	// check if the values match:
	for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "TEST 1 passed: All values correctly stored and retrieved!" << std::endl;
	delete [] mirror;


	// TEST 2
	// cannot access negative index: exception should be thrown.
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "TEST 2 passed: " << e.what() << '\n';
    }

	// TEST 3
	// out of bounds exception should be thrown.
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "TEST 3 passed: " << e.what() << '\n';
    }

	// TEST 4
	// create two arrays of strings
	Array<std::string> words1(3);
	words1[0] = "one";
	words1[1] = "two";
	words1[2] = "three";
	Array<std::string> words2(2);
	words2[0] = "ONE";
	words2[1] = "TWO";

	// testing copy constructor:
	Array<std::string> test(words1);
	for (int i = 0; i < 3; i++)
    {
        if (words1[i] != test[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
	}
	std::cout << "TEST 4 passed: All values correctly stored and retrieved!" << std::endl;

	// TEST 5
	// testing copy assignment operator
	test = words2;
	for (int i = 0; i < 2; i++)
    {
        if (test[i] != words2[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
	}
	std::cout << "TEST 5 passed: All values correctly stored and retrieved!" << std::endl;


	// TEST 6
	// create empty array and with default constructor and try to access it:
	// Exceptions should be thrown.
	Array<int> empty;
	try
	{
		std::cout << empty[0];
	}
	catch(const std::exception& e)
	{
		std::cerr << "TEST 6 passed: " << e.what() << '\n';
	}

	// TEST 7
	// copy into the empty array:
	empty = numbers;
	for (int i = 0; i < MAX_VAL; i++)
	{
        if (empty[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
	}
	std::cout << "TEST 7 passed: All values correctly stored and retrieved!" << std::endl;

	return 0;
}