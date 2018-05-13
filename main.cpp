#include <iostream>
#include "mathematicalFunction.hpp"
#include "neuronnalFunction.hpp"
#include "data.hpp"




int PerceptronEnter(float Enter1, float Enter2 , float Poid1 , float Poid2)
{
	int TotalOfFunction;
	TotalOfFunction = Enter1 * Poid1 + Enter2 * Poid2 ;
	return TotalOfFunction;


}
int CalculateCost(int desiredResult, float ResultGot)
{
	int cost;
	cost = desiredResult - ResultGot;
	return cost;



}
int ActivationFonction(float x)// no idea of name 
{

	int resultReturn;
	if (x  < 0)
	{
		resultReturn = 0;

	}
	if (x >= 0)
	{

		resultReturn = 1;
	}
	return resultReturn;


}
void PerceptronThink(int ValueToSubmited)
{
	if (ValueToSubmited = 0)
	{

		std::cout << "I Think it's a safe cookie" << std::endl;
	}
	if (ValueToSubmited = 1)
	{
		std::cout << "I Think It's a dangerous cookie" << std::endl;


	}
	else
	{
		CalculateCost(0, 1);

	}



}

int main()
{

std::cout << "test sigmoide : " << Sigmoide(-80000) << std::endl;


std::vector<double> test3{ 1,2,3 };
std::vector<double> test4{ 2,1.5,3};

DataForLearn_2  dataOR_1;
dataOR_1.firstEnter = 0;
dataOR_1.secondEnter = 0;
dataOR_1.resultWould = 0;
DataForLearn_2  dataOR_2;
dataOR_2.firstEnter = 0;
dataOR_2.secondEnter = 1;
dataOR_2.resultWould = 0;
DataForLearn_2  dataOR_3;
dataOR_3.firstEnter = 1;
dataOR_3.firstEnter = 0;
dataOR_3.resultWould = 0;

DataForLearn_2  dataOR_4;
dataOR_4.firstEnter = 1;
dataOR_4.secondEnter = 1;
dataOR_4.resultWould = 1;

std::vector<DataForLearn_2> vectorToDelete{dataOR_1,dataOR_2,dataOR_3};

neuron neuronTest2;
neuronTest2.Train(vectorToDelete);
std::vector<double> test333{ 1,1 };
neuronTest2.SetEnter(test333);

std::cout << neuronTest2.Compute() << std::endl;


// to delete /////////////////////////////////////////////////////////

/*
{
// must to be random initialised
float Poid1 = 0.5;
float Poid2 = 0.8;
// no idea of initialisation value

int SafeCookie = 0;
int PoisonCookie = 1;

float XPositionToSubmitted;
float YPositionToSubmited;
int   resultDesired;
// tout les exemple doivent pour l'instant etre apris a la mmain , en fournissant la
// coordonnée X pour le premier cin , Y pour le deuxieme et le resultat voulu
// pour le troisieme
while (true)
{
std::cin >> XPositionToSubmitted;
std::cin >> YPositionToSubmited;
std::cin >> resultDesired;
int k = PerceptronEnter(XPositionToSubmitted, YPositionToSubmited, Poid1, Poid2);
int a = ActivationFonction(k);
std::cout << "a =" << a << std::endl;
if (a != resultDesired) // on recalcul les poids
{

int cost = CalculateCost(resultDesired, a);
Poid1 = Poid1 + (resultDesired - a)*XPositionToSubmitted;
Poid2 = Poid2 + (resultDesired - a)*YPositionToSubmited;

std::cout << "weight 1 :  " << Poid1 << "  weight 2  " << Poid2 << std::endl;

}
else // les poids sont bon on touche a rien
{

std::cout << "Weight Ok: " << Poid1 << "  " << Poid2 << std::endl;


}




}

}
*/

//to delete ////////////////////////////////////////////////////////:
int test;
std::cin >> test;


}