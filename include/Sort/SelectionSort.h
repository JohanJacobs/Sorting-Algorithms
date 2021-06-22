#pragma once
#include <vector>    // std::vector
#include <algorithm> // std::swap

/// <summary>
/// Selection Sort - O(n^2)
/// brings the smallest value to the front of the list then iterate through the remainder moving IDx up by 1 each time  
/// </summary>
namespace SelectionSort
{
	static void SelectionSort(std::vector<int>& data)
	{
		size_t n = data.size();									// N
		size_t min_idx = 0;										// 1

		for (size_t i = 0; i < n - 1; i++)						// N*N
		{
			min_idx = i;

			// find the smallest value in 
			// the remained of the list 
			for (size_t j = i + 1; j < n; j++)					// N  
			{
				if (data[j] < data[min_idx])					// 1 
					min_idx = j;								// 1
			}
			std::swap(data[min_idx], data[i]);					// 1
		}
	}
}
