#pragma once
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <numeric>
#include <execution>
#include <cassert>





namespace Inf
{



	template<typename T>
	T quadraticLoss(T target, T x)
	{
		return pow((target - x), 2);
	}
	template<typename T>
	std::vector<T> quadraticLoss(std::vector<T> target, std::vector<T> x)
	{
		if (target.size() != x.size())
		{
			throw std::length_error("both array must have the same size");
		}
		std::vector<T> returnVector;
		returnVector.reserve(target.size());
		for (auto i = 0; i < target.size(); i++)
		{
			returnVector.push_back(return pow((target[i] - x[i]), 2););
		}
		return returnVector;
	}

	float tanhDerivative(float x)
	{///https://en.wikipedia.org/wiki/Hyperbolic_function   
		return static_cast<float>(1 - pow(tanh(x), 2));
	}

	template<typename T>
	T KullbackLeiblerDivergence(std::vector<T> vec1, std::vector<T> vec2)
	{
		if (vec1.size() != vec2.size())
		{
			throw std::length_error("both array must have the same size");
		}
		std::vector<T> vecForSum;
		for (auto i = 0; i < vec1.size(); i++)
		{

			vecForSum.push_back(vec2[i] * log(vec2[i] / vec1[i]));


		}
		return std::accumulate(vecForSum.begin(), vecForSum.end(), 0.0);




	}

	template<typename T>
	T CrossEntropy()
	{



	}

	template  <typename T>
	std::vector<T> Softmax(std::vector<T>& vec)
	{
		std::vector<T> exponentialvec;
		std::vector<T> softmaxReturn;
		softmaxReturn.reserve(vec.size());
		exponentialvec.reserve(vec.size());
		for (auto i = 0; i < vec.size(); i++)
		{
			exponentialvec.push_back(exp(vec[i]));
		}
		double expSum = std::accumulate(exponentialvec.begin(), exponentialvec.end(), 0.0);
		for (auto i = 0; i < vec.size(); i++)
		{

			softmaxReturn.push_back(exponentialvec[i] / expSum);
		}
		std::cout << expSum << std::endl;
		return softmaxReturn;
	}

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

	template <typename T>
	T  Median(std::vector<T>& vec)
	{
		std::sort(vec.begin, vec.end);

		if (vec.size() % 2 == 0)
		{
			return vec[vec.size() / 2] + vec[vec.size() / 2 + 1];
		}
		else
		{
			auto middle = int(vec.size(2));
			std::cout << middle << std::end;
			return vec[middle + 1];
		}

	}

	double Sigmoid(double x) {
		double exp_value;

		exp_value = exp((double)-x);
		return 1 / (1 + exp_value);
	}

	template <typename T> std::vector<double> v_Sigmoid(std::vector<T> &vector) {
		std::vector<T> SigmoidVector;
		for (auto i = 0; i < vector.size(); i++) {
			SigmoidVector.push_back(Sigmoid(vector[i]));
		}
		return SigmoidVector;
	}

	double SigmoidPrime(double x) { return x * (1 - x); }
	double n_SigmoidPrime(double x) { return Sigmoid(x)  * (1 - Sigmoid(x)); }

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
		if (vec1.size() != vec2.size())
		{
			throw std::length_error(std::string("Both arrays must have the same length"));
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

	std::vector<int> ToOneHot(int index, int range) {

		std::vector<int> oneHotvector(range, 0);
		oneHotvector[index] = 1;
		return oneHotvector;
	}

	float ReLU(float x) {
		if (x < 0)
		{
			return 0;
		}
		return x;
	}
}
