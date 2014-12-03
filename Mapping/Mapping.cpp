// Mapping.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <sstream>

std::string displayTime(int runtime)
{
	std::stringstream ss;
	int seconds = runtime % 60;
	int minutes = runtime / 60;
	if (minutes != 0)
	{
		ss << minutes 
			<< " Minutes, ";
	}
	ss << seconds 
		<< " Seconds";
	return ss.str();
}
std::vector<int> generateRuntimes()
{
	const int count = std::rand() % 5 + 1;
	std::vector<int> runtimes;
	for (int i = 0; i < count; i++)
	{
		runtimes.push_back(std::rand() % 1000 + 1);
	}
	return runtimes;
}
int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(0));
	std::map<std::string, std::vector<int>> runtimes;
	runtimes["Danny"]	= generateRuntimes();
	runtimes["Joey"]	= generateRuntimes();
	runtimes["Sally"]	= generateRuntimes();
	runtimes["Giggles"] = generateRuntimes();
	runtimes["Flargle"] = generateRuntimes();
	int runtimeTotal = 0;
	int averageRun;
	int count = 0;

	for (auto iter : runtimes)
	{
		int min = *std::min_element(iter.second.begin(), iter.second.end());
		int max = *std::max_element(iter.second.begin(), iter.second.end());

		std::cout << iter.first << std::endl;
		std::cout << "Minimum: " << displayTime(min)<< std::endl;
		std::cout << "Maximum: " << displayTime(max) << std::endl;

		for (auto runtime : iter.second)
		{
			count++;
			runtimeTotal += runtime;
			//std::cout << runtime << std::endl;
		}
		averageRun = runtimeTotal / count;
		std::cout << "Average: " << displayTime(averageRun) << std::endl;
		std::cout << "-------------" << std::endl << std::endl;

	}
	// Freeze Windows Console // 
	int freeze;
	std::cin >> freeze;

	return 0;
}

