#pragma once
#include "gruLayer.hpp"



namespace Inf
{
	class GruNetwork
	{
	public:

		GruNetwork(std::size_t numberOfLayer, std::size_t layerSize, std::size_t enterSize)
		{
			GruLayer layer(enterSize, 0);
			network.push_back(layer);



			for (auto i = 1; i < numberOfLayer; i++)
			{
				GruLayer layer(layerSize);
				network.push_back(layer);
			}

		}

		void Compute()
		{
			network[0].Compute();
			for (auto i = 1; i < network.size(); i++)
			{
				network[i].setEnter(network[i - 1]);
				network[i].Compute();

			}


		}

		void backPropagation(std::vector<float> target)
		{



		}

		void SetEnter(std::vector<float> enter)
		{
			network[0].SetEnter(enter);


		}


		std::vector<GruLayer> network;

	};


}