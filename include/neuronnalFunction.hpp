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
std::uniform_int_distribution<int> idRange(0, 50000);
std::uniform_real_distribution<> WeightIntialisation(-3, 3);

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

  void Train(std::vector<DataForLearn_2> data) {
    std::vector<double> EnterForLearn;

    double output = 0;
    int test = 0;
    for (unsigned int i = 0; i < 900; i++) {
      for (unsigned int i = 0; i < data.size(); i++) {
        EnterForLearn.push_back(data[i].firstEnter);
        EnterForLearn.push_back(data[i].secondEnter);
        this->SetEnter(EnterForLearn);
        this->SetWeight();

        output = this->Compute(Heaviside);
        if (output != data[i].resultWould) {

          Weight[0] = Weight[0] + (data[i].resultWould - output) * EnterForLearn[0] * 0.1;
          Weight[1] = Weight[1] + (data[i].resultWould - output) * EnterForLearn[1] * 0.1;
          Weight[2] = Weight[2] + (data[i].resultWould - output);
          std::cout << "weight 1 :" << Weight[0] << std::endl;
          std::cout << "weight 2 :" << Weight[1] << std::endl;
        }
        EnterForLearn.clear();
      }
    }
  }

  int Id = idRange(RandomEngine);
  std::function<float(float)> activationFunction;
  std::vector<double> Enter;
  std::vector<double> Weight;
  double exit;

private:
  int LearnIteration = 0;
};
