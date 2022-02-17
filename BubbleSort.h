#pragma once

#include <vector>
#include <iostream>

template<typename T>
auto BubbleSort(std::vector<T>* unsorted) -> void
{
	int count = 0;

	for (unsigned int i{ 0 }; i < unsorted->size() - 1; i++)
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
auto BubbleSort(std::vector<T>& unsorted) -> std::vector<T>
{
	BubbleSort(&unsorted);
	return unsorted;
}
