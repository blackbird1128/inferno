#pragma once
#include <vector>
#include <cmath>


namespace Inf
{

	template <class T> class Matrix
	{
	public:
		Matrix(int width, int height ,T fill = 0)
		{
			for (std::size_t i = 0; i < width * height; i++)
			{
				data.push_back(fill);
			}		
		}
		T& operator()(int width, int height)
		{
			return data[width * height];
		}

		std::vector<T>& _data()
		{
			return &data;
		}










	private:
		std::vector<T> data;
		
	};









































}
