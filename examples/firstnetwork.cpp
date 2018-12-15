#include <iostream>
#include "include/mathematicalFunction.hpp"
#include "include/neuronalFunction.hpp"
#include "include/data.hpp"
#include "include/neuronalnetwork.hpp"



Inf::Dataset TitanicDataset; //  dataset creation 
Inf::CSVparser parser; 
parser.open("titanictest.csv"); // .csv open by parser  
parser.dropEmptyValue(); // drop all the lines with values missing 
parser.setOutputCollumns(std::vector<int> {3}); // say to parser to put all the 3 collums in the output values 
TitanicDataset = parser.toDataset(); // get the data in datset 
int enterLayerSize = parser.getCollumnsNumber() - 1 ; // set the neural network enter size (equal to the dataset collums - 1 ) 
int hiddenLayerSize = 7; 
int hiddenLayerNumber = 2;
int exitLayerSize = 1; 
Inf::NeuronalNetwork TitanicNetwork(enterLayerSize,hiddenLayerSize,hiddenLayerNumber , exitLayerSize , Inf::Sigmoid); // set an network with 2 hiddens layer of set nodes and one exit nodes 

float learningRate = 0.150;
float learningIteration = 700;

 auto start = std::chrono::system_clock::now();
 TitanicNetwork.Train(TitanicDataset, learningRate, learningIteration); // train the network on the dataset , with an learning rate of 0.150 and 700 iterations 
 auto end = std::chrono::system_clock::now();

 std::chrono::duration<double> elapsed_seconds = end - start;
 std::time_t end_time = std::chrono::system_clock::to_time_t(end);

 std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

 TitanicNetwork.SoftReset(); // soft reset only remove all the enters but keep the weight 
 TitanicNetwork.SetEnter(std::vector<float> { 3, 1, 32  }); // set enters (3 : passengers class , 1 : sex : female , 32 : age )
 TitanicNetwork.Compute(); // compute the exit 
 std::cout <<  "has survided ?  " << TitanicNetwork.GetExit()[0] << std::endl; // get exit (for this data , the exit is the probability than a passenger survive )