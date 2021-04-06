/*
Another common technique to avoid having to pass a separate argument for the 
array's size is to make the first element of the array hold its size. Of 
course this only works for numeric arrays, but arrays of numbers are the 
most common kind.

Write the "copy_stock_prices" like before, but the first element contains the 
number of prices in the array, only copy those. 
*/
#include "mimir_testing.h"

void copy_stock_prices(double* source, double* dest){

} // copy_stock_prices

int main(){
    const int SIZE = 10;
    double source[SIZE] = {3, 13.4, 7, 11, 12, 13, 5, 2};
    double destination[SIZE] = {1, -1, 2, 3, 4, 5, 6, 7};
    double expected[SIZE] = {3, 13.4, 7, 11, 4, 5, 6, 7};
    copy_stock_prices(source, destination);
    for (int i = 0; i < SIZE; ++i) {
    ASSERT_EQ(expected[i], destination[i]);
    }

} // main