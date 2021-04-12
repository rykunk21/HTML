/*
One trick in C to work with arrays (and to not have to pass a size in a second 
argument with the array) is to have the array somehow encode where it ends 
inside the array. In C-style strings 
(https://www.learncpp.com/cpp-tutorial/66-c-style-strings/), the null terminator 
character ('\0') denotes the end of the string (though the character array can 
be longer).


Lets write a function that uses this approach. I have two arrays of 
doubles that will represent stock prices. Instead of specifying the size of 
the array, the first negative stock price indicates that the rest of the array 
doesn't contain actual data. Write a copy function named "copy_stock_prices" 
that takes two arguments: a pointer to the begining of the source array and a 
pointer to the beginning of the destination array. It should only copy over 
the valid data (and the terminating value).
*/

#include "mimir_testing.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <cassert>

void copy_stock_prices(double* source, double* dest){
    for(; *source >= 0; ++source){
        *dest = *source;
        ++dest;
    }
    *dest = *source;
} // copy_stock_prices

int main(){
    const int SIZE = 10;
    double source[SIZE] = {10, 13.4, 7, -5, 12, 13, 5, 2};
    double destination[SIZE] = {1, -1, 2, 3, 4, 5, 6, 7};
    double expected[SIZE] = {10, 13.4, 7, -5, 4, 5, 6, 7};
    copy_stock_prices(source, destination);
    for (int i = 0; i < SIZE; ++i) {
    ASSERT_EQ(expected[i], destination[i]);
    }
} // main