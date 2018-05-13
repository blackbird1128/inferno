#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "mathematicalFunction.hpp"
#include "data.hpp"




std::random_device RandomDevice;
std::default_random_engine RandomEngine(RandomDevice());
std::uniform_int_distribution<int>  idRange(0, 50000);
std::uniform_int_distribution<int>  WeightIntialisation(-2, 2);


class neuron
{
public:




	

	void SetEnter(std::vector<double> NeuronEnter)
	{
		
		NeuronEnter.swap(Enter);
		Enter.push_back(1);

	}
	void SetWeight()
	{

		if (Weight.empty())  //for not erase good weight
		{
			for (auto i = 0; i <Enter.size(); i++)
			{

				Weight.push_back(WeightIntialisation(RandomEngine));

			}


		}

		
	}
	double Compute()
	{
		double weightedSum = 0;
		if (Weight.size() != Enter.size())
		{

			std::cerr << "error Weight != Enter " << std::endl;
			std::cerr << "Weight =" << Weight.size() << std::endl;
			std::cerr << "Enter =" << Enter.size() << std::endl;
		}
		
		for (auto i = 0; i< Enter.size(); i++)
		{
			weightedSum = weightedSum + Enter[i] * Weight[i];

		}
		exit = Heaviside(weightedSum);
		return exit;
		
	
	}


	void Train(std::vector<DataForLearn_2> data)
	{
		std::vector<double> EnterForLearn;
		
		
		for (unsigned int i = 0; i < 2000; i++)
		{
			for (unsigned int i = 0; i < data.size() ; i++)
			{
				EnterForLearn.push_back(data[i].firstEnter);
				EnterForLearn.push_back(data[i].secondEnter);
				this->SetEnter(EnterForLearn);				
				this->SetWeight();
				double output = this->Compute();
				if (output != data[i].resultWould)
				{
					

					Weight[0] = Weight[0] + (data[i].resultWould - output)*EnterForLearn[0];
					Weight[1] = Weight[1] + (data[i].resultWould - output)*EnterForLearn[1];
					Weight[2] = Weight[2] + (data[i].resultWould - output);
				}
				EnterForLearn.clear();

			}

		}
		

		


		
	
	}
	void Connect( neuron neuron1 , neuron neuronToConnect)
	{

		neuronToConnect.Enter[0] = neuron1.exit;

	}


	int Id = idRange(RandomEngine);







private :

	std::vector<double> Enter;
	std::vector<double> Weight;
	double exit;
	int LearnIteration = 0;


};