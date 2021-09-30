// Main.cpp - Runs currently active project

#include "BubbleSort.h"


int main()
{
	std::vector<int> nums = { 0, 5, 2, 9, 3, 7, 5, 6, 3, 32, 64, 11, 3, 18, 148, 34, 256, 9875, 9874, 324001, 323010, 3, 7, 3, 9, 4, 11, 15 };
	OutputVec(nums);
	BubbleSort(&nums);
	OutputVec(nums);
}
