#pragma once

#include "include/mathematicalFunction.hpp"
#include <random>
#include <functional>
// (include in mathematical function )

std::random_device RandomDevices;
std::default_random_engine RandomEngines(RandomDevices());
std::uniform_real_distribution<> GruWeightIntialisation(-1, 1);
// https://towardsdatascience.com/understanding-gru-networks-2ef37df6c9be
namespace Inf
{
	class GruUnit
	{
	public:


		GruUnit(std::size_t enterSize)
		{

			Enter.resize(enterSize);


		}

		void init(std::size_t enterSize)
		{
			if (isNotInit)
			{
				Enter.resize(enterSize);
				previousEnter.resize(enterSize);

				isNotInit = false;
			}



		}


		void SetEnter(std::vector<float> Enters)
		{
			for (auto i = 0; i < Enters.size(); i++)
			{
				Enter.push_back(Enters[i]);

			}
		}
		void setWeight()
		{
			if (isNotWeightInit)
			{
				for (auto i = 0; i < Enter.size(); i++)
				{

					EnterUpdateWeights.push_back(GruWeightIntialisation(RandomEngines));
					PreviousEnterUpdateWeight.push_back(GruWeightIntialisation(RandomEngines));
					EnterResetWeight.push_back(GruWeightIntialisation(RandomEngines));
					PreviousEnterResetWeight.push_back(GruWeightIntialisation(RandomEngines));
					Weight_W.push_back(GruWeightIntialisation(RandomEngines));
					Weight_U.push_back(GruWeightIntialisation(RandomEngines));


				}
				isNotWeightInit = false;


			}

		}




		float Compute()
		{


			for (auto i = 0; i < Enter.size(); i++)
			{
				UpdateGate.push_back(Inf::Sigmoid(Enter[i] * EnterUpdateWeights[i] + previousEnter[i] * PreviousEnterUpdateWeight[i]));
				ResetGate.push_back(Inf::Sigmoid(Enter[i] * EnterResetWeight[i] + previousEnter[i] * PreviousEnterResetWeight[i]));

				CurrentMemoryContent.push_back(tanh(Enter[i] * Weight_W[i] + ResetGate[i] * (previousEnter[i] * Weight_U[i])));
				FinalMemory.push_back(UpdateGate[i] * previousEnter[i] + (1 - UpdateGate[i]) * CurrentMemoryContent[i]);

				previousEnter.clear();
				previousEnter.push_back(FinalMemory[i]);
			}

			return 0;
		}


		bool isNotInit = true;
		bool isNotWeightInit = true;


		std::vector<float> Enter;


		std::vector<float> previousEnter;//ht-1




		std::vector<float> EnterUpdateWeights; // used in update Gate Wz
		std::vector<float> PreviousEnterUpdateWeight; // used in update Gate Uz

		std::vector<float> EnterResetWeight;  // Wr
		std::vector<float> PreviousEnterResetWeight; //Ur

		std::vector<float> Weight_W; // Wg
		std::vector<float> Weight_U;  //Ug




		std::vector<float> UpdateGate;//zt
		std::vector<float> ResetGate; //rt
		std::vector<float> CurrentMemoryContent;//gt
		std::vector<float> FinalMemory; // output 
	};
}
