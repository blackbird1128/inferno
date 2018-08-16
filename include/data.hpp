#pragma once
#include <iostream>
#include <string>
#include <vector>

struct DataForLearn_1 {
  double enter;
  double resultWould;
};

struct DataForLearn_2 {
  float firstEnter;
  float secondEnter;
  float resultWould;
};

struct DataForLearn_n {
  std::vector<float> Enter;
  std::vector<float> exitExpected;

  double resultWould;

  void clear()
  {
	  Enter.clear();
	  exitExpected.clear();
	  resultWould = 0;

  }

};

struct Dataset {
  std::vector<DataForLearn_n> dataset;
};
