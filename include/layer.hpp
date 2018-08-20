#pragma once
#include "neuronnalFunction.hpp"
#include <iostream>

class Layer {

public:
  Layer(int LayerSize) {

    for (auto i = 0; i < LayerSize; i++) {
      neuron neuronOflayer;
      neuronLayer.push_back(neuronOflayer);
    }
  }
  Layer() {}

  void AddNeuron() {

    neuron neuronOfLayer;
    neuronLayer.push_back(neuronOfLayer);
  }

  void RemoveNeuron() {
    if (!neuronLayer.empty()) {
      neuronLayer.pop_back();
    }
	else {
      std::cerr << "can't remove neuron , layer is empty " << std::endl;
    }
  }

  template <typename T> void ComputeDelta(std::vector<T> resultExpected) {
    if (neuronLayer.size() != resultExpected.size()) {
      throw std::length_error("both array must have the same size ");
    }
    std::vector<T> LayerError;
    for (auto i = 0; i < neuronLayer.size(); i++) {
      Error.push_back(resultExpected[i] - neuronLayer[i].exit);
    }
    for (auto i = 0; i < neuronLayer.size(); i++) {

      Deltas.push_back(Error[i] * n_SigmoidPrime(neuronLayer[i].enterSum));
    }
  }
  

  void ComputeDelta(Layer previousLayer) {

    for (auto i = 0; i < neuronLayer.size(); i++) {
      float error = 0;
      for (auto j = 0; j < previousLayer.neuronLayer.size(); j++)
	  {
        error += previousLayer.neuronLayer[j].Weight[i] * previousLayer.Deltas[j];
      }

      Error.push_back(error);
    }
    for (auto i = 0; i < neuronLayer.size(); i++)
	{
      Deltas.push_back(Error[i] * SigmoidPrime(neuronLayer[i].exit));
    }
  }

  void updateWeight(float learningRate) {
    for (auto i = 0; i < neuronLayer.size(); i++) {
      for (auto w = 0; w < neuronLayer[i].Weight.size(); w++)
	  {
        neuronLayer[i].Weight[w] += (learningRate * Deltas[i] * neuronLayer[i].Enter[w]);
      }
    }
  }

  void Compute(std::function<float(float)> functionToUse) {
	ActivationFunction = functionToUse;

    for (auto i = 0; i < neuronLayer.size(); i++)
	{
      float result = neuronLayer[i].Compute(ActivationFunction);
      exit.push_back(result);
    }
  }

  void SetEnter(Layer previousLayer) {
    for (auto j = 0; j < previousLayer.exit.size(); j++) {
      for (auto i = 0; i < neuronLayer.size(); i++) {

        neuronLayer[i].Enter.push_back(previousLayer.exit[j]);
		neuronLayer[i].enterSum += previousLayer.exit[j]; // necessary for using any derivative function 
        enter.push_back(previousLayer.exit[j]);
		enterSum += previousLayer.exit[j];

        if (neuronLayer[i].Weight.size() < neuronLayer[i].Enter.size()) {
          neuronLayer[i].Weight.push_back(WeightIntialisation(RandomEngine));
        }
      }
    }
  }
  void SetEnter(std::vector<float> EntertoSet) // hum name is bad
  {

    if (EntertoSet.size() != neuronLayer.size()) {
      throw std::string{"Enter size != neuronLayer size "};
    }
    for (auto i = 0; i < EntertoSet.size(); i++) 
	{
	  enterSum += EntertoSet[i];
      neuronLayer[i].Enter.push_back(EntertoSet[i]);
	  neuronLayer[i].enterSum += EntertoSet[i];
      enter.push_back(EntertoSet[i]);
    }
  }

  std::function<float(float)> ActivationFunction;
  std::vector<neuron> neuronLayer;
  std::vector<float> Error;
  std::vector<float> Deltas;
  std::vector<float> exit;
  std::vector<float> enter;
  float enterSum = 0; //unused 
};