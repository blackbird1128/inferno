#pragma once
#include <iostream>
#include <cmath>







int Heaviside(float x)// no idea of name 
{

	int result;
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




float Sigmoide(float x)
{
	float exp_value;
	float return_value;

	exp_value = exp((double)-x);

	return_value = 1 / (1 + exp_value);

	return return_value;



}


float ComputeCost(float resultDesired, float ResultGet)
{
	float cost;
	cost = resultDesired - ResultGet;
	return cost;
}





