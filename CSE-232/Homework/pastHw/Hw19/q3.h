#pragma once
#include <string>

class Parrot {
  std::string name;
  
 public:
  Parrot(std::string);
  std::string speak() const ;
};