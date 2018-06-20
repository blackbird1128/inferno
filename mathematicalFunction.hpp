#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>







int Heaviside(double x)
{

	int result = 0 ;
	if (x  < 0)
	{
		result = 0;

	}
	if (x >= 0)
	{

		result = 1;
	}
	return result;


}




double Sigmoid(double x)
{
	double exp_value;
	double return_value;

	exp_value = exp((double)-x);

	return_value = 1 / (1 + exp_value);

	return return_value;



}
double SigmoidPrime(double x)
{

	return Sigmoid(x) * (1 - Sigmoid(x));

}


float ComputeCost(float resultDesired, float ResultGet)
{
	float cost;
	cost = resultDesired - ResultGet;
	return cost;
}


template<typename T>
T Dot(std::vector<T> vec1, std::vector<T> vec2)
{
	if (vec1.size() != vec2.size())
	{
		throw std::length_error(std::string("Both arrays must have the same length"));


	}
	double  sum = 0;
	for (auto i = 0; i < vec1.size(); i++)
	{

		sum += (vec1[i] * vec2[i]);
	}
	T result = sum;
	return result;

}

std::vector<int> ToOneHot(int index, int range)
{

	std::vector<int> oneHotvector(range, 0);
	oneHotvector[index] = 1;
	return oneHotvector;


}






