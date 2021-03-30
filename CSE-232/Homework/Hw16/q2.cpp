/*
You need to make a custom type called a "HousePrice". This type represents an 
address and its estimated Zillow price. It has two data members, a string with 
the house's address (named "address") and a double representing the price 
Zillow estimates for the house (named "price").

Additionally, you need to write a function (not a member function, a regular 
one) that takes a const reference to a vector of HousePrice and returns 
the average of the price in that vector as a double. This function is called 
"get_average_price".

Use "zillow.h" as your header file and "zillow.cpp" as your implementation 
file.
*/

#include "q2.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <numeric>
using std::accumulate;

double get_average_price(const vector<HousePrice> &house_prices){
    double total = accumulate(house_prices.begin(), house_prices.end(), 0.0, 
           [](double &init, const HousePrice &arg2){
               return init + arg2.price;
    });

    return total / static_cast<double>(house_prices.size());
}

int main(){
    
    return 0;
}