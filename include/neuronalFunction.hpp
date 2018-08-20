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

class neuron {
public:
  void SetEnter(std::vector<double> neuronEnter) {

    neuronEnter.swap(Enter);
    Enter.push_back(1); // threshold
  }
  void SetWeight() {

    if (Weight.empty()) // for not erase good weight
    {
      for (auto i = 0; i < Enter.size() - 1; i++) {

        Weight.push_back(WeightIntialisation(RandomEngine));
      }
      Weight.push_back(0); // threshold Weight
    }
  }

  double Compute(std::function<float(float)> functionToUse) {
    double weightedSum = 0;
	activationFunction = functionToUse;
    if (Weight.size() != Enter.size()) {

      std::cerr << "error Weight size != Enter size " << std::endl;
      std::cerr << "Weight size =" << Weight.size() << std::endl;
      std::cerr << "Enter  size =" << Enter.size() << std::endl;
      return 666;
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
