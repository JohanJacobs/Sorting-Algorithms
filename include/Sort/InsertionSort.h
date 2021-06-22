#pragma once
#include <vector>    // std::vector
#include <algorithm> // std::swap

/// <summary>
/// Insertion Sort - O(n^2)
/// Brings the smallest value to the front of the list then iterate through the remainder moving IDx up by 1 each time  
/// Basically you split the array in two pieces (sorted,unsorted) as you move an unsorted part to the correct location 
/// in the sorted array patr you move the Index on. this continues till the index == end.
/// </summary>
namespace InsertionSort
{
	static void InsertionSort(std::vector<int>& data)
	{
		int n = (int)data.size();
		int key = 0;

		//iterate through the list
		for (int i = 1; i < n; i++)			// N^2
		{
			key = data[i];							// 1
			int j = i - 1;						// 1

			while (j >= 0 && data[j] > key)			// N
			{
				data[j + 1] = data[j];				// 1
				j = j - 1;							// search backward in to the array to check where the data item data[i] first 
			}

			data[j + 1] = key;						// 1
		}
	}
}
