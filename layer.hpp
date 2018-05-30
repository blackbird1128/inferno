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

	std::vector<neuron> neuronLayer;




};