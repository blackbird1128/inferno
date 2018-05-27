#pragma once
#include <iostream>
#include <vector>
#include "neuronnalFunction.hpp"

class NeuronalNetwork
{
public:
	NeuronalNetwork(int enterLayerSize , int layerSize  , int numberOfLayer  , int exitLayerSize  )
	{
	
		for (auto i = 0; i < enterLayerSize;i++)
		{

			std::cout << enterLayerSize << std::endl;
			neuron enterNeuron;
			enterLayer.push_back(enterNeuron);
		}

		for (auto i = 0; i < numberOfLayer; i++)
		{
			for (auto i = 0; i < layerSize; i++)
			{
				neuron  hiddenLayerNeuron;
				hiddenLayer.push_back(hiddenLayerNeuron);

			}


		}

		for (auto i = 0; i < exitLayerSize; i++)
		{
			  
			neuron exitNeuron;
			exitLayer.push_back(exitNeuron);


		}


	}






private:

	std::vector<neuron> enterLayer;
	std::vector<neuron> hiddenLayer;
	std::vector<neuron> exitLayer;


};
