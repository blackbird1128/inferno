#pragma once
// must be herit of an generic layer class later
#include "include/data.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cmath>



namespace Inf
{
	class CSVparser {
	public:
		CSVparser() {}

		CSVparser(std::string filename)
		{
			csvReader.open(filename);
		}

		bool open(std::string filename)
		{
			csvReader.open(filename);
			return true;
		}
		Dataset toDataset() // bad name to change
		{

			parseHeader();
			std::string line;
			while (parseLines(line) == true) {
			}

			return csvDataset;
		}

		std::size_t getCollumnsNumber()
		{
			return header.size();
		}

		void setDefaultValue(float value)
		{
			defaultValue = value;
		}

		void dropEmptyValue()
		{
			keepEmptyValue = false;
		}

		void setOutputCollumns(std::vector<int> outputIndex)
		{
			exitIndex = outputIndex;
			std::sort(exitIndex.begin(), exitIndex.end());
		}

	private:
		void parseHeader()
		{
			if (csvReader.is_open())
			{

				header.push_back("");
				char c = ' ';
				int i = 0;
				while (c != '\n')
				{

					bool onComma = false;
					csvReader.get(c);
					if (c == ',')
					{
						++i;
						onComma = true;
						header.push_back("");

					}
					if (onComma == false)
					{
						// std::cout << c;
						header[i] += c;
					}

				}

			}
			else
			{
				throw std::invalid_argument("you must open a file for parse it ");
			}
		}

		bool parseLines(std::string line)
		{
			char comma = ',';
			char endline = '\n';
			std::vector<std::string> lines;
			if (csvReader.is_open())
			{
				lines.push_back("");
				char c = ' ';
				int i = 0;
				while (c != '\n')
				{
					if (c == EOF)
					{
						return false;
					}

					bool onComma = false;
					csvReader.get(c);
					if (c == ',')
					{
						++i;
						onComma = true;
						lines.push_back("");
					}

					if (onComma == false)
					{
						lines[i] += c;
					}

					if (csvReader.eof()) // manualy added for this moment
					{
						csvReader.close();
						return false;
					}
				}
			}
			else
			{
				throw std::invalid_argument("you must open a file for parse it ");
			}

			auto j = 0;
			for (auto i = 0; i < lines.size(); i++)
			{
				if (i == exitIndex[j])
				{
					try {
						linesData.exitExpected.push_back(std::stof(lines[i]));
						j++;
					}
					catch (std::invalid_argument)
					{
						if (keepEmptyValue == false)
						{
							linesData.clear();
							j = 0;
							keepData = false;
							break;

						}
						else
						{
							linesData.exitExpected.push_back(defaultValue);

						}
					}

				}
				else
				{

					try
					{
						linesData.Enter.push_back(std::stof(lines[i]));
					}
					catch (std::invalid_argument)
					{
						if (keepEmptyValue == false)
						{
							linesData.clear();
							j = 0;
							keepData = false;
							break;
						}
						else
						{
							// linesData.Enter.push_back(defaultValue);

						}

					}
				}
			}
			j = 0;

			if (keepData == true)
			{
				csvDataset.dataset.push_back(linesData);
				linesData.clear();

			}
			else
			{
				keepData = true; // reset states
			}

			return true;
		}



		float defaultValue = 0;
		std::vector<int> exitIndex = { 0 };
		bool keepEmptyValue = true;
		bool keepData = true;
		std::size_t collumsNumber;
		std::ifstream csvReader;
		std::vector<std::string> header;
		DataForLearn_n linesData;
		Dataset csvDataset;
	};
} // namespace