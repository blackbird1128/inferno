#pragma once
#include <iostream>
#include "neuronnalFunction.hpp"




class Layer
{

public:

	Layer(int LayerSize)
	{

		for (auto i = 0; i < LayerSize; i++)
		{
			neuron neuronOflayer;
			neuronLayer.push_back(neuronOflayer);

	   }


	}
	Layer()
	{



	}
	void AddNeuron()
	{

		neuron neuronOfLayer;
		neuronLayer.push_back(neuronOfLayer);
	}
	void RemoveNeuron()
	{
		if (!neuronLayer.empty())
		{
			neuronLayer.pop_back();
		}
		else
		{
			std::cerr << "can't remove neuron , layer is empty " << std::endl;
		}
			

	}



	std::vector<neuron> neuronLayer;




};