#pragma once

#include <string>

struct MathVector{
  // data members
  int x = 0;
  int y = 0;

  // 2 constructors
  // =default uses the values of the data members (above).
  // No other work is required here. You're welcome!
  MathVector()=default;
  MathVector(int x_, int y_) : x(x_), y(y_) {};

  // 4 function members you must write
  MathVector add(const MathVector&);
  MathVector mult(int);
  int mult(const MathVector&);
  double magnitude();
};

// a generic function you must write
std::string vec_to_str(const MathVector&);
