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
	template<typename T>
	void Compute(T ActivationFunction)
	{
		for (auto i = 0; i < neuronLayer.size(); i++)
		{


			auto result = neuronLayer[i].Compute(ActivationFunction);
			exit.push_back(result);
		}


	}
	void SetEnter(Layer previousLayer)
	{
		for (auto j = 0; j < previousLayer.exit.size(); j++)
		{
			for (auto i = 0; i < neuronLayer.size(); i++)
			{

				neuronLayer[i].Enter.push_back(previousLayer.exit[j]);
				neuronLayer[i].SetWeight();
			}
           

		}



	}
	void SetEnter(std::vector<float> EntertoSet) // hum name is bad 
	{
        
		if (EntertoSet.size() != neuronLayer.size())
		{
			throw std::string{ "Enter size != neuronLayer size " };
		}
		for (auto i = 0; i < EntertoSet.size(); i++)
		{

			neuronLayer[i].Enter.push_back(EntertoSet[i]);
			neuronLayer[i].SetWeight();
		}

			
	

	}

	std::vector<neuron> neuronLayer;
	std::vector<float> exit;
	std::vector<float> enter;



};