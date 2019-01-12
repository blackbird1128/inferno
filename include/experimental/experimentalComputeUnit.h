#pragma once
#include "exterimentalComputeGrid.h"
#include "../mathematicalFunction.hpp"
#include "../matrix.hpp"
#include "../utility.hpp"
#include <functional>
#include <stdexcept>
#include <utility>


enum  ComputeType{ adding =0 , multiplication =1  , function = 2  , weightMultiplication =  3};
namespace Inf
{
	namespace Exp
	{
		class Unit
		{
		using activationFunction = std::function<float(float)>;
		public:
			Unit(std::size_t enterSize )
			{
				EnterSize = enterSize;
			}
			void AddComputeStep(ComputeType step, std::function<float(float)> func, std::function<float(float)> funcDerivative)
			{
				Functions.push_back(func);
				Derivative.push_back(funcDerivative);
				ComputeList.push_back(function);

			}
			void ResetWeight()
			{
				for (auto i = 0; i < Weights.size(); i++)
				{
				
				}
			}
			void AddComputeStep(ComputeType step)
			{
				if (step == function)
				{
					throw std::invalid_argument("no compute function passed in argument ");
				}
				if (step == weightMultiplication)
				{
					ComputeGrid grid;
					grid.MakeWeights(-0.1, 0.1, 1); // to fix 
					Weights.push_back(grid);
					ComputeList.push_back(weightMultiplication);

				}

			}
			void SetEnter(std::vector<double> enters)
			{
				float sum = 0;
					for (auto i : enters)
					{
						sum += i;
						
					}
					Results.Grid.push_back(sum);	
			}
			void Compute()
			{
			
				for (auto i = 0; i < ComputeList.size(); i++)
				{

					if (ComputeList[i] == weightMultiplication)
					{
						WeightCache.push_back(Results.Grid);
						for (auto i = 0; i < Results.Grid.size(); i++)
						{
							Results.Grid[i] = Results.Grid[i] * Weights[WeightsPosition].Grid[i];
						}
						++WeightsPosition;
					}
					if (i == 1)
					{

					}
					if (ComputeList[i] == function)
					{
						WeightCache.push_back(Results.Grid);
						for (auto i = 0; i < Results.Grid.size(); ++i)
						{
							Cache.push_back(Results.Grid);
							Results.Grid[i] = Functions[a](static_cast<float>( Results.Grid[i]));
							
						}
						++a;

					}





				}
			}
			void ComputeError(float error ) // rename paramters 
			{
				auto totalFunction = Cache.size();
				Errors.push_back(error);
				int totalDerivative = Derivative.size();



				
				for (auto i = ComputeList.size()-1; i > 0; i--)
				{
					
					
					if (ComputeList[i] == function)
					{

						Errors.push_back(Errors.back() * Derivative[totalDerivative-1](Cache[totalFunction-1][0]));// fix me im ugly =< 
						--totalFunction;
						totalDerivative--;
					}
					if (ComputeList[i] == weightMultiplication)
					{
						Errors.push_back(Errors.back() * Weights[WeightsPosition - 1].Grid[0] );
						--WeightsPosition;

					}
				}
				auto totalWeight = Weights.size();
				for (auto i = 0; i < ComputeList.size(); i++)
				{
					if (ComputeList[i] == weightMultiplication)
					{
						Delta.push_back(Errors[i + 1] * WeightCache[totalWeight - 1][0]);
						totalWeight--;
					}
				
				}
				for (auto i =0 ; i < Weights.size();i++)
				{
		
					Weights[i].Grid[0] = ( Weights[i].Grid[0] -0.5*Delta[i]);
				}

			}
			void SoftReset()
			{
				Errors.clear();
				WeightCache.clear();
				Cache.clear();
				Delta.clear();
				a = 0;
				WeightsPosition = 0;
				Enters.clear();
				Results.Grid.clear();



			}
			void train()
			{
				for (auto i = 0; i < 3600; i++)
				{
					std::vector<double> abc{ 0.2 };
					SetEnter(abc);

					Compute();

					auto error = Results.Grid[0] - 0.8;

					ComputeError(error);
				    displayExit();
					SoftReset();

				}

			}
			void displayExit()
			{
				for (auto i : Results.Grid)
				{
					std::cout << i << std::endl;
				}
			}




			ComputeGrid Results;
			std::vector<double> Errors;

		private:
			std::vector<ComputeType> ComputeList;
			std::vector<std::vector<double>> WeightCache;
			std::vector<std::vector<double>> Cache;
			std::vector<double> Delta;
			std::size_t a = 0;
			std::size_t WeightsPosition{0};


			std::vector<activationFunction> Functions;
			std::vector<activationFunction> Derivative;
			std::size_t EnterSize;
			std::vector<float> Enters;

			std::vector<ComputeGrid>  Weights;

		};



	}

}