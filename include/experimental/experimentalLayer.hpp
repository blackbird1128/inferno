#pragma once
#include "../mathematicalFunction.hpp"
#include "experimentalComputeUnit.h"
#include "../data.hpp"


namespace Inf
{
	namespace Exp
	{
		class ComputeNetwork 
		{
		public :
			void AddLayer(Unit unit, std::size_t size)
			{
				std::vector<Inf::Exp::Unit> layer;
				unit.SoftReset();
				for (auto i = 0; i < size; i++)
				{
					layer.push_back(unit);
				}
				Layers.push_back(layer);
			}
			void SetEnter(std::vector<float> enters)
			{
				for (auto i = 0; i < Layers[0].size(); i++)
				{
					Layers[0][i].SetEnter(std::vector<double>{enters[i]});
				}
			}
			void Compute()
			{
			    
				for (auto i = 0; i < Layers.size()-1; i++)
				{
				
					std::vector<double> allEnters;
					for (auto j = 0; j < Layers[i].size(); j++)
					{
						Layers[i][j].Compute();
						allEnters.push_back(Layers[i][j].Results.Grid[0]);
					
					}
					for (auto j = 0; j < Layers[i+1].size(); j++)
					{
						Layers[i + 1][j].SetEnter(allEnters);


					}
	
					
				}

				for (auto j = 0; j < Layers.back().size(); j++)
				{
					Layers.back()[j].Compute();

				}

				
			}
			void ComputeError(std::vector<float> realExit)
			{
				for (auto i = 0; i < Layers.back().size(); i++)
				{
					Layers.back()[i].ComputeError(Layers.back()[i].Results.Grid[0] - realExit[i]);
	

				}
				for (auto i = Layers.size() - 2; i > 0; i--)
				{
					float totalError = 0;
					for (auto j = 0; j < Layers[i + 1].size(); j++)
					{
						totalError += Layers[i + 1][j].Errors.back();
					}
					for (auto j = 0; j < Layers[i].size(); j++)
					{
						Layers[i][j].ComputeError(totalError);

					}



				}

			}
			void DisplayExit()
			{
				for (auto i = 0; i < Layers.back().size(); i++)
				{
					std::cout << Layers.back()[i].Results.Grid[0] << " " ;
				}
				std::cout << std::endl;
			}
			void SoftReset()
			{
				for (auto i = 0; i < Layers.size(); i++)
				{
					for (auto j = 0; j < Layers[i].size(); j++)
					{
						Layers[i][j].SoftReset();
					}
				}

			}
			void Train(Inf::Dataset data , int iterations )
			{

				
			 	 for (auto i = 0; i < iterations ; i++)
				{
					for (auto j = 0; j < data.dataset.size(); j++)
					{
						SetEnter(data.dataset[j].Enter);
						Compute();
						ComputeError(data.dataset[j].exitExpected);
						SoftReset(); 

					}

			
				}
			
               

			}



		private:
			std::vector<std::vector<Inf::Exp::Unit>> Layers;

		};



	}























}