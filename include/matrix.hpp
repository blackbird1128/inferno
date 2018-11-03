#pragma once
#pragma once
#include <vector>
#include <cmath>
#include <ostream>
#include <algorithm>

namespace Inf
{

	template <class T> class Matrix
	{
	public:
		Matrix(int width, int height, T fill = 0)
		{
			m_width = width;
			m_height = height;
			for (std::size_t i = 0; i < width * height; i++)
			{
				data.push_back(fill);
			}
		}
		T& operator()(int height, int width)
		{
			return data[(width * height) + width];
		}

		std::vector<T> _data()
		{
			return data;
		}
		int GetWidht()
		{
			return m_width;
		}
		int getHeight()
		{
			return m_height;
		}
		int RowIndex(int Row)
		{
			return row * (m_width );
		}
		auto begin()
		{
			return data.begin();
		}
		auto end()
		{
			return data.end();
		}
		auto max()
		{
			
			return  *std::max_element(data.begin(), data.end());
		}
		T& max(std::size_t collums)
		{
			T maxElement = 0; // naive but ...
			for (auto i = collums * m_width; i < (collums * m_width) + (m_width - 1); i++)
			{
				if (data[i] > maxElement)
				{
					maxElement = data[i];
				}
			}
			return maxElement;
		}


	private:
		std::vector<T> data;
		int m_width;
		int m_height;

	};




}
