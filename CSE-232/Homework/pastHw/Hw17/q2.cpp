/*
Python lists have a handy feature where you can use negative indices to get 
at elements counting from the end of the list. x[-1] returns the last element
in x and x[-2] returns the penultimate element and so on. Implement a struct 
named "PythonicIntVector" in the files "PythonicIntVector.h" and 
"PythonicIntVector.cpp" that supports the push_back and at methods of a vector 
of ints. However, be sure to add the functionality of negative indices.

Don't forget that the at method still should throw exceptions for invalid 
indices (just like in Python)!
*/

#include "q2.h"
#include <iostream>
using std::cout; using std::endl;
#include <cassert>

int PythonicIntVector::at(const int& arg){
    if (arg >= 0){
        return v.at(arg);
    } else {
        return v.at(v.size() + arg);
    }
}

void PythonicIntVector::push_back(const int& arg){
    v.push_back(arg);
}   

int main(){
    
    PythonicIntVector v;
    // ASSERT_ANY_THROW(v.at(0));
    std::cout << "pushing 8" << std::endl;
    v.push_back(8);
    assert(v.at(0) == 8);
    std::cout << "checking negative index" << std::endl;
    assert(v.at(-1) == 8);
    std::cout << "checking invalid indices" << std::endl;
    // ASSERT_ANY_THROW(v.at(1));
    // ASSERT_ANY_THROW(v.at(-2));
    std::cout << "pushing 12" << std::endl;
    v.push_back(12);
    assert(v.at(0) == 8);
    assert(v.at(1) == 12);
    std::cout << "checking negative index" << std::endl;
    
    assert(v.at(-1) == 12);
    assert(v.at(-2) == 8);
    std::cout << "checking invalid index" << std::endl;
    // ASSERT_ANY_THROW(v.at(-3));
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    assert(v.at(-2) == 2);
    assert(v.at(-4) == 12);
} // main