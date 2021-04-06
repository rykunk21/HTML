/*
I've written some code in "code.h" and "code.cpp" that has a Parrot that can 
"speak".  However, only the first test case is passing. Please correct me 
code so that the last two test cases also pass.
*/
#include "mimir_testing.h"
#include "q3.h"
#include <string>
using std::literals::operator""s;

Parrot::Parrot(std::string name_) : name(name_) {}

std::string Parrot::speak() const {
  return "Hello! My name is " + name + "! Hello!";
}


int main(){
    /*CXX_FLAGS -Wall -Wpedantic -Werror*/
   
    const Parrot p("Sparrow");
    std::string result = p.speak();
    ASSERT_EQ(result, "Hello! My name is Sparrow! Hello!"s);
    Parrot p2("Captain");
    Parrot const * p_ptr = &p2;
    result = p_ptr->speak();
    ASSERT_EQ(result, "Hello! My name is Captain! Hello!"s);

} // main