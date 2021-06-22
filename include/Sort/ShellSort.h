#pragma once
#include <vector>    // std::vector
#include <algorithm> // std::swap
namespace ShellSort
{
	/// <summary>	
	///  Shell sort runs in O(n^2) quadratic time 
	///  Algorithm: Two for loops iterating through the data set and moves the biggest value to the back
	/// </summary>
	static void ShellSort(std::vector<int>& data)		// O(N^2) = 3N^2 + N
	{
		int n = (int)data.size();
		
		for (int gap = n / 2; gap > 0; gap /= 2) // large gaps and decrease size of gaps
		{
			// gapped insertion sort for this gap size.
			// first gap elements data[0...gap-1] are already in gapped order
			// keep adding one more element until the entire array is gap sorted
			for (int i = gap; i < n; i += 1)
			{
				int temp = data[i];
				int j;
				for (j = i; j > gap && data[(size_t)j - gap] > temp; j -= gap)
					data[j] = data[(size_t)j - gap];

				data[j] = temp;
			}
		}

	}
}