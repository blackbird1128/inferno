#pragma once
#include "data.hpp"
#include "mathematicalFunction.hpp"
#include <cassert>
#include <iostream>
#include <random>
#include <string> // for test only
#include <vector>
#include <functional>

std::random_device RandomDevice;
std::default_random_engine RandomEngine(RandomDevice());
std::uniform_real_distribution<> WeightIntialisation(-0.5, 0.5);
namespace Inf
{


	class neuronUnit {
	public:
		void SetEnter(std::vector<double> neuronEnter)
		{
			neuronEnter.swap(Enter);
		}

		void SetWeight()
		{
			if (Weight.empty()) // for not erase good weight
			{
				for (auto i = 0; i < Enter.size() - 1; i++) {

					Weight.push_back(WeightIntialisation(RandomEngine));
				}
			}
		}

		inline double Compute(const std::function<float(float)>& functionToUse) {
			double weightedSum = 0;
			activationFunction = functionToUse;
			if (Weight.size() != Enter.size()) {
				throw std::length_error("the two array must have the same size ");

			}

			for (auto i = 0; i < Enter.size(); i++) {
				weightedSum = weightedSum + Enter[i] * Weight[i];
			}

			exit = activationFunction(weightedSum);
			return exit;
		}


		std::function<float(float)> activationFunction;
		std::vector<double> Enter;
		std::vector<double> Weight;
		double exit;
		double enterSum;  // set in layer.hpp


	};
}