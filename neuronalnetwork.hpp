#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
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
		std::vector<float> bla{ 2,3 };
		enterLayer.SetEnter(bla);
		std::cout << " enter layer enter size :" << enterLayer.enter.size() << std::endl;
		for(auto i = 0; i < enterLayer.enter.size();i++)
		{
			enterLayer.exit.push_back(Sigmoid(enterLayer.enter[i]));
		}
		std::cout <<  "enter exit size" << enterLayer.exit.size() << std::endl;
		hiddenLayer[0].SetEnter(enterLayer);
		hiddenLayer[0].Compute(Sigmoid);

		
		for (auto i = 1; i < hiddenLayer.size()-1;i++)
		{

			if (i + 1 > hiddenLayer.size() - 1) { break; }
			hiddenLayer[i + 1].SetEnter(hiddenLayer[i]);
			hiddenLayer[i].Compute(Sigmoid);
			

		}
		exitLayer.SetEnter(hiddenLayer[hiddenLayer.size()-1]); // because vector index begin at 0 
		exitLayer.Compute(Sigmoid);

		return 0;

	}
	float BackPropagation(DataForLearn_n target , float learningRate , float momentumFactor)
	{
		if(target.ExitExpected.size()!= exitLayer.exit.size())
		{
			throw std::length_error(std::string("Exit layer  as not the same size than than target data  "));

		
		}
		std::vector<float> output_deltas;
		for (auto i : exitLayer.exit)
		{
			float error = 0;
			error = target.ExitExpected[i] - i;
			output_deltas.push_back(error);

		}
		std::vector<float> hidden_deltas;
		std::reverse(hiddenLayer.begin(), hiddenLayer.end());
		for (auto j = 0 ; j < hiddenLayer[0].neuronLayer.size();j++)
		{
			auto currentLayerExit = hiddenLayer[0].neuronLayer[j].exit;
			auto currentLayerWeight = hiddenLayer[0].neuronLayer[j].Weight;
			auto Delta = currentLayerExit * (1 - currentLayerExit);
			float sumOfPonderedDelta = 0;
			for (auto i = 0; i < exitLayer.neuronLayer.size(); i++)
			{
				  
				sumOfPonderedDelta += currentLayerWeight[j] * output_deltas[i];

			}
			Delta += sumOfPonderedDelta;
			hidden_deltas.push_back(Delta);




		}
		for(auto i = 1 ;i < hiddenLayer.size();i++ )
		{

			for (auto j = 0; j < hiddenLayer[i].neuronLayer.size(); i++)
			{
				auto currentLayerExit = hiddenLayer[i].neuronLayer[j].exit;
				auto currentLayerWeight = hiddenLayer[i].neuronLayer[j].Weight;
				auto Delta = currentLayerExit * (1 - currentLayerExit);
				float sumOfPonderedDelta = 0;
				for (auto b = 0; b < exitLayer.neuronLayer.size(); b++)
				{

					sumOfPonderedDelta += currentLayerWeight[j] * output_deltas[b];

				}
				Delta += sumOfPonderedDelta;
				hidden_deltas.push_back(Delta);


			}		
		}




		for (auto i = 0; i < exitLayer.neuronLayer.size(); i++)
		{

			for (auto j = 0; j < exitLayer.neuronLayer[i].Weight.size();j++)
			{
				auto actualWeight = exitLayer.neuronLayer[i].Weight[j];
				exitLayer.neuronLayer[i].Weight[j] = actualWeight + learningRate * hiddenLayer[0].neuronLayer[j].exit * output_deltas[j];


			}


		}
		std::reverse(hidden_deltas.begin(), hidden_deltas.end());
		for (auto d = 0; d < hiddenLayer.size(); d++)
		{

			for (auto k = 0; k < hiddenLayer[d].neuronLayer.size()-1; k++)
			{
				for (auto j = 0; j < hiddenLayer[d].neuronLayer[k].Weight.size();j++)
				{
					auto actualWeight = hiddenLayer[d].neuronLayer[k].Weight[j];
					auto actualEnter = hiddenLayer[d].neuronLayer[k].Enter[j];
					hiddenLayer[d].neuronLayer[k].Weight[j] = actualWeight + learningRate * actualEnter * hidden_deltas[(1*d+1*k+1)-1] ;


				}




			}



		}









		std::reverse(hiddenLayer.begin(), hiddenLayer.end());
		std::reverse(hidden_deltas.begin(), hidden_deltas.end());


          



	}




	float exit;
private:

	Layer enterLayer;
	std::vector<Layer> hiddenLayer; 
	Layer exitLayer;
    

};
