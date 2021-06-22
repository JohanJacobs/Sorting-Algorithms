#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Helpers/Timer.h"

//sorting algorithms 
#include "Sort/BubbleSort.h"
#include "Sort/SelectionSort.h"
#include "Sort/InsertionSort.h"
#include "Sort/ShellSort.h"

//data files from https://www.coursera.org/learn/algorithms-part1
std::vector<std::string> FileNames ={
	"Data/1Kints.txt",
	"Data/2Kints.txt",
	"Data/4Kints.txt",
	"Data/8Kints.txt",
	"Data/16Kints.txt",
	"Data/32Kints.txt"
};

std::vector<int> GetData(const std::string& filename)
{
	std::fstream file;
	file.open(filename, std::ios::in);

	if (!file.is_open())
	{
		std::cout << filename << " not found!\n";
		exit(EXIT_FAILURE);
	}

	std::vector<int> data;
	std::string line;

	while (std::getline(file, line))
	{
		data.push_back(std::stoi(line));
	}
	file.close();

	return data;
}

/// <summary>
/// Template function that takes a sorting function to run data over 
/// </summary>
/// <param name="func">Sortingfunction that accepts an std::vector<int></param>
/// <param name="label">Label name for the sorting function</param>

template<typename TF>
void SimulateSort(TF&& func, const std::string& label)
{
	std::cout << "Running " << label << "\n";		
	std::vector < std::pair<std::string, long long>> m_Results;
		
	for (size_t FileID = 0; FileID < FileNames.size(); FileID++)
	{
		// load relevant data set
		auto data = GetData(FileNames[FileID]);

		JTime::Stopwatch stopwatch(FileNames[FileID], false);

		// run the sorting function provided 
		func(data);

		// save the results			
		m_Results.push_back(std::make_pair(FileNames[FileID], stopwatch.Elapsed()));
	}

	// print results	
	for (auto v : m_Results)
	{
		std::cout << "    " << v.first << ": " << v.second << " microseconds (" << v.second / 1000 << " ms).\n";
	}
	std::cout << "\n";
}

int main()
{	
	std::cout << "Running sorting algorithms.\n\n";	

	//other sorting
	SimulateSort(ShellSort::ShellSort, "ShellSort");	
	SimulateSort(InsertionSort::InsertionSort, "InsertionSort");
	SimulateSort(SelectionSort::SelectionSort,"SelectionSort");
	SimulateSort(BubbleSort::BubbleSort, "BubbleSort");

	return EXIT_SUCCESS;
}