#pragma once
#include "../utility.hpp"
#include <stdexcept>

class ComputeGrid
{
public:

	void MakeWeights(std::size_t  min, std::size_t max, std::size_t len)
	{

		std::random_device RandomDevices;
		std::default_random_engine RandomEngines(RandomDevices());
		std::uniform_real_distribution<> WeightIntialisation(-0.5, 0.5);

		for (auto i = 0; i < len; i++)
		{
			Grid.push_back(WeightIntialisation(RandomEngines));
		}
	}
	std::vector<double> Data()
	{
		return Grid;
	 }

	void operator*(ComputeGrid& b)
	{
		if (b.Grid.size() != this->Grid.size())
		{
			throw std::invalid_argument("both grid must have the same size");
		}
		for (auto i = 0; i < b.Grid.size(); i++)
		{
			Grid[i] = Grid[i] * b.Grid[i];
		}
	}
	// copy paste power ... 
	void operator+(ComputeGrid& b)
	{
		if (b.Grid.size() != this->Grid.size())
		{
			throw std::invalid_argument("both grid must have the same size");
		}
		for (auto i = 0; i < b.Grid.size(); i++)
		{
			Grid[i] = Grid[i] + b.Grid[i];
		}
	}
	void operator-(ComputeGrid& b)
	{
		if (b.Grid.size() != this->Grid.size())
		{
			throw std::invalid_argument("both grid must have the same size");
		}
		for (auto i = 0; i < b.Grid.size(); i++)
		{
			Grid[i] = Grid[i] + b.Grid[i];
		}
	}

	std::vector<double> Grid;
private:


};