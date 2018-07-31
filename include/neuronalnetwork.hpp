#pragma once
#include "layer.hpp"
#include "neuronnalFunction.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <functional>

class NeuronalNetwork {

public:

 
  NeuronalNetwork(int enterLayerSize, int layerSize, int numberOfLayer,  int exitLayerSize , std::function<float(float)> functionToUse) {

	  activationFunction = functionToUse;
    for (auto i = 0; i < enterLayerSize; i++) {
      enterLayer.AddNeuron();
    }

    for (auto j = 0; j < numberOfLayer; j++) {
      Layer oneHiddenLayer(layerSize); // no idea of name
      hiddenLayer.push_back(oneHiddenLayer);
    }

    for (auto i = 0; i < exitLayerSize; i++) {

      exitLayer.AddNeuron();
    }
  }

  void SetEnter(std::vector<float> enter)
  {
	enterLayer.SetEnter(enter);
  }

  void SoftReset() {
    for (auto i = 0; i < enterLayer.neuronLayer.size(); i++) {
      enterLayer.neuronLayer[i].Enter.clear();
      enterLayer.neuronLayer[i].exit = 0;
      enterLayer.enter.clear();
      enterLayer.exit.clear();
      enterLayer.Deltas.clear();
      enterLayer.Error.clear();
    }
    for (auto i = 0; i < hiddenLayer.size(); i++) {
      for (auto j = 0; j < hiddenLayer[i].neuronLayer.size(); j++) {
        hiddenLayer[i].neuronLayer[j].Enter.clear();
        hiddenLayer[i].neuronLayer[j].exit = 0;
        hiddenLayer[i].enter.clear();
        hiddenLayer[i].exit.clear();
        hiddenLayer[i].Deltas.clear();
        hiddenLayer[i].Error.clear();
      }
    }
    for (auto i = 0; i < exitLayer.neuronLayer.size(); i++) {
      exitLayer.neuronLayer[i].Enter.clear();
      exitLayer.neuronLayer[i].exit = 0;
      exitLayer.enter.clear();
      exitLayer.exit.clear();
      exitLayer.Deltas.clear();
      exitLayer.Error.clear();
    }
  }

  
  float Compute() {  // set the activation Fonction used in the network

    for (auto i = 0; i < enterLayer.enter.size(); i++) {
      this->enterLayer.exit.push_back(enterLayer.enter[i]);
    }

    this->hiddenLayer[0].SetEnter(enterLayer);

    for (auto i = 0; i < hiddenLayer.size() - 1; i++) {

      this->hiddenLayer[i].Compute(activationFunction);
      this->hiddenLayer[i + 1].SetEnter(hiddenLayer[i]);
    }
    this->hiddenLayer[hiddenLayer.size() - 1].Compute(Sigmoid);
    this->exitLayer.SetEnter( hiddenLayer[hiddenLayer.size() - 1]); // because vector index begin at 0
    this->exitLayer.Compute(activationFunction);

    return 0;
  }

  float BackPropagation(DataForLearn_n &target, float learningRate) {
    if (target.exitExpected.size() != exitLayer.exit.size()) {
      throw std::length_error(std::string(
          "Exit layer  as not the same size than than target data  "));
    }

    exitLayer.ComputeDelta(target.exitExpected);

    std::reverse(hiddenLayer.begin(), hiddenLayer.end());
    hiddenLayer[0].ComputeDelta(exitLayer);

    for (auto i = 1; i < hiddenLayer.size(); i++) {
      hiddenLayer[i].ComputeDelta(hiddenLayer[i - 1]);
    }
    exitLayer.updateWeight(learningRate);
    for (auto i = 0; i < hiddenLayer.size(); i++) {

      hiddenLayer[i].updateWeight(learningRate);
    }

    std::reverse(hiddenLayer.begin(), hiddenLayer.end());
  }

  void Train(Dataset &dataset, float learningRate, float learningIteration ) {

    for (auto i = 0; i < learningIteration; i++) {

      for (auto i = 0; i < dataset.dataset.size(); i++) {

        this->SetEnter(dataset.dataset[i].Enter);
        this->Compute();
        this->BackPropagation(dataset.dataset[i], learningRate);
        this->SoftReset();
      }
    }
	this->SetEnter(std::vector<float>{0.2f, 0.8f});
	this->Compute();
	std::cout << this->exitLayer.neuronLayer[0].exit << std::endl;

  }
  void testFunc()
  {
	  activationFunction = ReLU;
	  std::cout << activationFunction(55) << std::endl;;
  }

  std::function<float(float)> activationFunction;
  Layer enterLayer;
  std::vector<Layer> hiddenLayer;
  Layer exitLayer;
  float exit;
};
