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
		std::vector<float> TestComputeEnteR{ 2,5,4,5,8};
		enterLayer.SetEnter(TestComputeEnteR);
		enterLayer.Compute(Sigmoide);
		hiddenLayer[0].SetEnter(enterLayer);
		for (auto i = 1; i < hiddenLayer.size()-1;i++)
		{

			if (i + 1 > hiddenLayer.size() - 1) { break; }
			hiddenLayer[i + 1].SetEnter(hiddenLayer[i]);
			hiddenLayer[i].Compute(Sigmoide);


		}
		exitLayer.SetEnter(hiddenLayer[hiddenLayer.size()-1]); // because vector index begin at 0 
		exitLayer.Compute(Sigmoide);

		return 2;

	}




	float exit;
private:

	Layer enterLayer;
	std::vector<Layer> hiddenLayer; 
	Layer exitLayer;
    

};
