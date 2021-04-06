/*
You're going to write a vector class called "FunnyVector", because it's kind 
of like a vector, but a funny one. For starters, it can only contain numbers 
(ints, to be precise). Also, unlike std::vector, FunnyVector keeps all its 
ints in sorted order. Even worse, when you call size() on it, it gives the 
sum of its elements, not the number of elements. And to top it all off, if 
you put in numbers so that the sum goes over a threshold, all the numbers 
are erased. Fortunately, this threshold can be set when a FunnyVector is 
created. And for the pruposes of testing, you can get() a std::vector<int> 
from a FunnyVector to see its contents.

Provide the interface to your FunnyVector in funny_vector.hpp. You should 
write the implementation of FunnyVector in funny_vector.cpp

See the sample test case for how a FunnyVector should behave.

*/
#include "q5.h"
#include <iostream>
using std::cout; using std::endl;
#include <cassert>
#include <numeric>
using std::accumulate;
#include <algorithm>
using std::sort;

FunnyVector::FunnyVector(const int& arg){
    threshold = arg;
}

int FunnyVector::size(){
    return accumulate(v.begin(), v.end(), 0);
}

void FunnyVector::push_back(const int& arg){
    v.push_back(arg);
    sort(v.begin(), v.end());
    if ((*this).size() > threshold){
        v.clear();
    }
    
}

vector<int> FunnyVector::get(){
    return v;
}


int main(){
    
 
    FunnyVector v{42};  // set threshold to 42
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    /*
    auto ans1 = v.get();
    std::vector<int> expected1 {2, 3, 5};
    assert(ans1 == expected1);  // adds them in sorted order
    assert(v.size() == 10); // size is the sum
    */
    v.push_back(7);
    v.push_back(3);
    v.push_back(2);
    v.push_back(7);
    /*
    auto ans2 = v.get();
    std::vector<int> expected2 {2, 2, 3, 3, 5, 7, 7};
    assert(ans2 == expected2);  // still in sorted order
    assert(v.size() == 29); // size is the sum
    */
    v.push_back(33); // sum goes over 42, all numbers erased
    v.push_back(7); // 7 is now the only number
    v.push_back(5);
    auto ans3 = v.get();
    for (int elem: ans3){cout << elem << endl;}
    std::vector<int> expected3 {5, 7};
    assert(ans3 == expected3);  // still in sorted order
    assert(v.size() == 12); // size is the sum

}