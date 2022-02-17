#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

template<typename T>
auto MergeSort(std::vector<T> unsorted) -> std::vector<T>
{
	if (unsorted.size() > 1)
	{
		size_t mid = size_t(unsorted.size() / 2);
		std::vector<T> left = MergeSort<T>(std::vector<T>(unsorted.begin(), unsorted.begin() + mid));
		std::vector<T> right = MergeSort<T>(std::vector<T>(unsorted.begin() + mid, unsorted.end()));

		std::vector<T> sorted;
		auto iter1 = left.begin();
		auto iter2 = right.begin();

		while (iter1 != left.end() && iter2 != right.end())
		{
			if (*iter1 < *iter2)
			{
				sorted.emplace_back(*iter1);
				iter1++;
			}
			else
			{
				sorted.emplace_back(*iter2);
				iter2++;
			}
		}

		if (iter1 != left.end())
			for (; iter1 != left.end(); iter1++)
				sorted.emplace_back(*iter1);
		else
			for (; iter2 != right.end(); iter2++)
				sorted.emplace_back(*iter2);
		return sorted;
	}

	return unsorted;
}

template<typename T>
auto MergeSort(std::vector<T>* unsorted) -> void
{
	*unsorted = MergeSort<T>(*unsorted);
}
