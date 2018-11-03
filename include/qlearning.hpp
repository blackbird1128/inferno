#pragma once
#include "matrix.hpp"
#include <random>


namespace Inf 
{
	class QLearningAgent
	{
	public:
		QLearningAgent()
		{
		
		}


		Inf::Matrix<float> train(float gamma , Inf::Matrix<float> trainingMat , std::size_t iterations , float NonPassableValue  , std::size_t finalState )
		{
			Inf::Matrix<float> qMatrix(trainingMat.GetWidht() , trainingMat.getHeight()  , 0);
		    std::default_random_engine generator;
			std::uniform_int_distribution<int> StateDistribution(0,trainingMat.getHeight()-1);
			std::uniform_int_distribution<int> ActionDistribution(0, trainingMat.GetWidht() - 1);


			for (std::size_t i = 0; i < iterations; i++)
			{
				int randomState = StateDistribution(generator);
				int actualState = randomState;
				bool onFinalState = false;

				while (onFinalState != true)
				{
					
					int randomAction = ActionDistribution(generator);
					while (trainingMat(actualState, randomAction) == NonPassableValue)
					{
						
						randomAction = ActionDistribution(generator);
					}
					qMatrix(actualState, randomAction) = trainingMat(actualState, randomAction) + (gamma * qMatrix.max(randomAction));
					//std::cout << "max(qMatrix)" << qMatrix.max(randomAction) << std::endl;
					//std::cout << "trainingMat ( " << actualState << " , " << randomAction << " ) " << "  : " << trainingMat(actualState, randomAction)   << std::endl;
					//std::cout << "qMatrix ( " << actualState << " , " << randomAction << " ) " << "  : " << qMatrix(actualState, randomAction) << std::endl;

					actualState = randomAction;

					if (actualState == finalState)
					{
						onFinalState = true;

					}
				}



			}
			return qMatrix;

			
			
	


		}





	private:
		

	};


}

