#include <vector> 
#include <list>
#include <string>
#include <iostream>
#include "easyfind.hpp"

// clang++ -Wall -Wextra -Werror -std=c++98 main.cpp

int main(void) {
	{
		std::cout << "=== test with vector of int ===" << std::endl;
		int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::vector<int> v(array, array + 10);
		try {
			easyfind(v, 8);
			std::cout << "Element is found" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			easyfind(v, 18);
			std::cout << "Element is found" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n=== test with list of float ===" << std::endl;
		float array[10] = {0.1, 1.22, 22.3, 3.444, 444.5, 5.6666, 6666.7, 7.88888, 88888.9, 9.00000};
		std::list<float> v(array, array + 10);
		try {
			easyFind(v, 8.9);
			std::cout << "Element is found" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			easyFind(v, 1.22);
			std::cout << "Element is found" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}