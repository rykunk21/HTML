 #include <iostream>
#include <string>
using std::string;
#include <sstream>
#include <math.h>

#include "math_vector.hpp"

string vec_to_str(const MathVector& v){ //"x:y"
  string x_str = std::to_string(v.x);
  string y_str = std::to_string(v.y);
  string output="";
  output += x_str;
  output += ':';
  output += y_str;
  return output;
}

MathVector MathVector::add(const MathVector& v){
  MathVector new_math_vec;
  new_math_vec.x = x + v.x;
  new_math_vec.y = y + v.y;
  return new_math_vec;
}

MathVector MathVector::mult(int num){
  MathVector math_vec;
  math_vec.x = x * num;
  math_vec.y = y * num;
  return math_vec;
}

int MathVector::mult(const MathVector& v){
  int output=0;
  output += x * v.x;
  output += y * v.y;
  return output;
}

double MathVector::magnitude(){
  double output=0;
  output += pow(x,2);
  output += pow(y,2);
  output = pow(output, .5);
  return output;
}

int main (){
  
  MathVector v1;
  MathVector v2(3,2);
  MathVector v3(10,12);

  std::cout << "V1:" << vec_to_str(v1) 
       	    << ", V2:" << vec_to_str(v2) 
            << ", V3:" << vec_to_str(v3) 
            << std::endl;


  MathVector add_result = v1.add(v2);
  std::cout << "Sum of v1 and v2 is: " << vec_to_str(add_result) << std::endl;
  MathVector add_result2 = v2.add(v3);
  std::cout << "Sum of v2 and v3 is: " << vec_to_str(add_result2) << std::endl;

  int scalar = 20;
  MathVector mult_result = v2.mult(scalar);
  std::cout << "mult of v2 and " << scalar << " is: " << vec_to_str(mult_result) << std::endl;

  int result = v1.mult(v2);
  std::cout << "mult of v1 and v2 is: " << result << std::endl;

  int result2 = v2.mult(v3);
  std::cout << "mult of v2 and v3 is: " << result2 << std::endl;
  
  double dbl_result = v2.magnitude();
  std::cout << "magnitude of v2 is: " << dbl_result << std::endl; 
}
