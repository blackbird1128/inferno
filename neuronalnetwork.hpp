#pragma once
#include <iostream>
#include <vector>
#include "neuronnalFunction.hpp"
#include "layer.hpp"

class NeuronalNetwork
{
public:
	NeuronalNetwork(int enterLayerSize , int layerSize  , int numberOfLayer  , int exitLayerSize  )
	{
	
		for (auto i = 0; i < enterLayerSize;i++)
		{
			enterLayer.AddNeuron();
           
		}

		for (auto j = 0; j < numberOfLayer; j++)
		{
			Layer  oneHiddenLayer(layerSize); //no idea of name 
			hiddenLayer.push_back(oneHiddenLayer);


		}

		for (auto i = 0; i < exitLayerSize; i++)
		{
			  
			exitLayer.AddNeuron();


		}


	}
	float Compute()
	{



	}





private:

	Layer enterLayer;
	std::vector<Layer> hiddenLayer; 
	Layer exitLayer;


};
