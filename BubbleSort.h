#pragma once

#include <vector>
#include <iostream>

template<typename T>
void BubbleSort(std::vector<T>* unsorted)
{
	int count = 0;

	for (int i{ 0 }; i < unsorted->size() - 1; i++)
	{
		if (unsorted->at(i) > unsorted->at(i + 1))
		{
			T temp = unsorted->at(i + 1);
			unsorted->at(i + 1) = unsorted->at(i);
			unsorted->at(i) = temp;
			count++;
		}
	}
	if (count != 0)
		BubbleSort(unsorted);
	return;
}

template<typename T>
void OutputVec(const std::vector<T>& vec)
{
	std::cout << "{ ";
	for (const auto& item : vec)
	{
		std::cout << item << ((item != vec.back()) ? ", " : " }");
	}
	std::cout << std::endl;
}
