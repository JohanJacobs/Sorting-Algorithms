#pragma once
#include <vector>    // std::vector
#include <algorithm> // std::swap
namespace BubbleSort
{
	/// <summary>	
	///  Bubble sort runs in O(n^2) quadratic time 
	///  Algorithm: Two for loops iterating through the data set and moves the biggest value to the back
	/// </summary>
	/// <param name="data"> vector<int> </param>
	/// 
	static void BubbleSort(std::vector<int>& data)		// O(N^2) = 3N^2 + N
	{
		size_t n = data.size();
		bool swapped = true;
		while (swapped)									// N * 3N + 1
		{
			swapped = false;							// 1
			for (size_t i = 0; i < n-1; i++)			// N * 3 = 3N
			{
				if (data[i] > data[i + 1])				// 1
				{
					std::swap(data[i], data[i + 1]);	// 1
					swapped = true;						// 1
				}
			}
		}
	}
}