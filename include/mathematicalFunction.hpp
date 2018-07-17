#pragma once
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

int Heaviside(double x) {

  int result = 0;
  if (x < 0) {
    result = 0;
  }
  if (x >= 0) {

    result = 1;
  }
  return result;
}

double Sigmoid(double x) {
  double exp_value;
  double return_value;

  exp_value = exp((double)-x);

  return_value = 1 / (1 + exp_value);

  return return_value;
}

template <typename T> std::vector<double> v_Sigmoid(std::vector<T> &vector) {
  std::vector<T> SigmoidVector;
  for (auto i = 0; i < vector.size(); i++) {
    SigmoidVector.push_back(Sigmoid(vector[i]));
  }
  return SigmoidVector;
}

double SigmoidPrime(double x) { return x * (1 - x); }

template <typename T> std::vector<T> SigmoidPrime(std::vector<T> &vector) 
{
  std::vector<T> SigmoidPrimeVector;
  for (auto i = 0; i < vector.size(); i++) {

    SigmoidPrimeVector.push_back(vector[i] * (1 - vector[i]));
  }
  return SigmoidPrimeVector;
}

float ComputeCost(float resultDesired, float ResultGet) {
  float cost;
  cost = resultDesired - ResultGet;
  return cost;
}

template <typename T>
std::vector<T> Dot(std::vector<T> vec1, std::vector<T> vec2) {
  std::vector<T> dotResult;
  if (vec1.size() != vec2.size()) {
    throw std::length_error(
        std::string("Both arrays must have the same length"));
  }

  for (auto i = 0; i < vec1.size(); i++) {

    dotResult.pushback(vec1[i] * vec2[i]);
  }

  return dotResult;
}

template <typename T> T DotSum(std::vector<T> vec1, std::vector<T> vec2) {
  if (vec1.size() != vec2.size()) {
    throw std::length_error(
        std::string("Both arrays must have the same length"));
  }
  float sum = 0;
  for (auto i = 0; i < vec1.size(); i++) {

    sum += vec1[i] * vec2[i];
  }
  return T(sum);
}

float returnValue(float value)
{
  return value; 
}

std::vector<int> ToOneHot(int index, int range) {

  std::vector<int> oneHotvector(range, 0);
  oneHotvector[index] = 1;
  return oneHotvector;
}
