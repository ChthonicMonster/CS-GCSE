#include <random>
#include <iostream>

#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

auto GenerateNumberList(int length, int min, int max) -> std::vector<int>;

template<typename T>
auto OutputVec(const std::vector<T>& vec) -> void;

int main()
{
	while (true)
	{
		int alg_choice = 1; int ls_length = 10; int min_val = 0; int max_val = 100;
		std::cout << "\nSorting Algorithms:" << std::endl << "1. BubbleSort\n2. MergeSort\n3. QuickSort" << std::endl;
		do
		{
			std::cout << "Enter algorithm of choice: ";
			try {
				std::string temp;
				std::getline(std::cin, temp, '\n');
				alg_choice = std::stoi(temp);
			}
			catch (...) { std::cout << "Please enter a value between 1 and 3" << std::endl; }
		} while (alg_choice < 1 || alg_choice > 3);
		std::cout << "Enter preferred length of randomly generated list (10): "; 
		try {
			std::string temp;
			std::getline(std::cin, temp, '\n');
			ls_length = std::stoi(temp);
		} catch (...) {}
		std::cout << "Enter minimum value that can appear in list (0): ";
		try {
			std::string temp;
			std::getline(std::cin, temp, '\n');
			min_val = std::stoi(temp);
		} catch (...) {}
		do
		{
			std::cout << "Enter maximum value that can appear in list (100): ";
			try {
				std::string temp;
				std::getline(std::cin, temp, '\n');
				max_val = std::stoi(temp);
				if (max_val <= min_val) {
					std::cout << "Maximum value must be greater than the minimum value" << std::endl;
				}
			}
			catch (...) { max_val = 100; }
		} while (max_val <= min_val);

		auto nums = GenerateNumberList(ls_length, min_val, max_val);
		
		if (alg_choice == 1)
			std::cout << "[BubbleSort] { ";
		if (alg_choice == 2)
			std::cout << "[MergeSort] { ";
		if (alg_choice == 3)
			std::cout << "[QuickSort] { ";

		std::cout << "length: " << ls_length << ", between: [" << min_val << ", " << max_val << "] }" << std::endl;

		OutputVec(nums);

		if (alg_choice == 1)
			BubbleSort(&nums);
		else if (alg_choice == 2)
			MergeSort(&nums);
		else if (alg_choice == 3)
			QuickSort(&nums);

		OutputVec(nums);
	}
}

auto GenerateNumberList(int length, int min, int max) -> std::vector<int>
{
	std::vector<int> list;
	srand((unsigned)(time(NULL)));
	for (int i{ 0 }; i < length; i++) {
		int num = (rand() % (max - min + 1)) + min;
		list.push_back(num);
	}
	return list;
}

template<typename T>
auto OutputVec(const std::vector<T>& vec) -> void
{
	std::cout << "{ ";
	for (unsigned int i{ 0 }; i < vec.size(); i++)
	{
		std::cout << vec.at(i) << ((i != vec.size() - 1) ? ", " : " }");
	}
	std::cout << std::endl;
}
