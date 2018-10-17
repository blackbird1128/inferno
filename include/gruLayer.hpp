#pragma once
#include "gruUnit.hpp"
#include <vector>
#include <utility>

class GruLayer
{
public:
	GruLayer( std::size_t layerSize , std::size_t enterSize = 0)
	{
		for (auto i = 0; i < layerSize; i++)
		{
			GruUnit unit(enterSize);
			Layer.push_back(unit);

		}

	}


	void backPropagation(std::vector<float > target  , std::pair<std::vector<float>, std::vector<float> > & error1and2)
	{
		//https://cran.r-project.org/web/packages/rnn/vignettes/GRU_units.html
		std::vector<float> err1;
		std::vector<float> err2;
		std::vector<float> err3;
		std::vector<float> err4;
		std::vector<float> err5;
		std::vector<float> err6;
		std::vector<float> err7;
		std::vector<float> err8;
		std::vector<float> err9;
		std::vector<float> err10;
		std::vector<float> err11;
		std::vector<float> err12;
		std::vector<float> err13;
		std::vector<float> err14;
		std::vector<float> err15;
		std::vector<float> err16;
		std::vector<float> err17;
		std::vector<float> err18;
		std::vector<float> err19;
		std::vector<float> err20;
		std::vector<float> err21;
		std::vector<float> err22;
		std::vector<float> err23;
		std::vector<float> err24;


		std::vector<float> errorWeightW;
		std::vector<float> errorWeightU;
		std::vector<float> errorEUW; // enter update Weight ...
		std::vector<float> errorPEUW; // Previous
		std::vector<float> errorERW; // Reset
		std::vector<float> errorPERW;

		
		for (auto i = 0; i < Layer.size(); i++)
		{		
			auto error = quadraticLoss(target[i], Layer[i].FinalMemory[0]); // fixme
			err1.push_back(std::get<0>(error1and2)[0]);
			err2.push_back(std::get<1>(error1and2)[0]);
			err3.push_back(err1[i] + err2[i]);
			err4.push_back((1 - Layer[i].FinalMemory[0])*err3[i]);
			err5.push_back(err3[i] * Layer[i].previousEnter[0]);
			err6.push_back(1 - err5[i]);
			err7.push_back(err3[i] * Layer[i].CurrentMemoryContent[0]);
			err8.push_back(err3[i] * Layer[i].UpdateGate[0]);
			err9.push_back(err7[i] + err8[i]);
			err10.push_back(err8[i] * tanhDerivative(Layer[i].CurrentMemoryContent[0]));
			err11.push_back(err9[i] * SigmoidPrime(Layer[i].UpdateGate[0]));
			err12.push_back(err10[i] * Layer[i].Weight_W[0]);
			err13.push_back(err10[i] * Layer[i].Weight_U[0]);
			err14.push_back(err11[i] * Layer[i].EnterUpdateWeights[0]);
			err15.push_back(err11[i] * Layer[i].PreviousEnterUpdateWeight[0]);
			err16.push_back(err13[i] * Layer[i].previousEnter[0]);
			err17.push_back(err13[i] * Layer[i].ResetGate[0]);
			err18.push_back(err17[i] * SigmoidPrime(Layer[i].ResetGate[0]));
			err19.push_back(err17[i] + err4[i]);
			err20.push_back(err18[i] * Layer[i].EnterResetWeight[0]);
			err21.push_back(err18[i] * Layer[i].PreviousEnterResetWeight[0]);
			err22.push_back(err21[i] + err15[i]);
			err23.push_back(err19[i] + err22[i]);
			err24.push_back(err12[i] + err14[i] + err20[i]);




			// weight update to move :


		}

	








	}



	void Compute()
	{

		for (auto i = 0; i < Layer.size(); i++)
		{
			Layer[i].Compute();
						
		}
	}
	void SetEnter(std::vector<float> enter)
	{
		for (auto k = 0; k < Layer.size(); k++)
		{
		
			Layer[k].Enter.push_back(enter[k]);
			
		}
		//must to be separated 
		for (auto k = 0; k < Layer.size(); k++)
		{

			Layer[k].setWeight();
			Layer[k].init(Layer[k].Enter.size());

		}


	}
	std::size_t size()
	{
		return Layer.size();
	}

	void setEnter(GruLayer previousLayer)
	{
		if(previousLayer.size() != Layer.size())
		{ 
			throw std::length_error("both array must have the same size ");
		}

		for (auto i = 0; i < Layer.size(); i++)
		{
			Layer[i].init(previousLayer.Layer[i].FinalMemory.size());
			Layer[i].setWeight();
			for (auto j = 0; j < Layer[i].Enter.size(); j++)
			{
				Layer[i].Enter[j] = previousLayer.Layer[i].FinalMemory[j];

			}
		
		}


	}






	


	std::vector<GruUnit> Layer;
	std::vector<float> exit;


};
