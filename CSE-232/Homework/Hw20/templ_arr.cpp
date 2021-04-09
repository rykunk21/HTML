/*
Write a function (named "templated_array_copy") that takes two parameters 
(two arrays of the same type). It copies the first array into the second. 
Note, it the arrays are different sizes, only copy what fits.
*/
#include "mimir_testing.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <cassert>

#include <algorithm>
using std::copy_n;

template <typename T, size_t size1, size_t size2>
void templated_array_copy(T (&source)[size1], T (&dest)[size2]){

    if (sizeof(source) > sizeof(dest)){
        // copy_n copies n elements begining at arg1
        // https://www.cplusplus.com/reference/algorithm/copy_n/
        copy_n(std::begin(source), sizeof(dest) / sizeof(T), std::begin(dest));
    } else {
        copy_n(std::begin(source), sizeof(source) / sizeof(T), std::begin(dest));
    }
} // temp_arr_copy


void test1(){
    double source[] = {1, 2, 5, 6};
    double dest[] = {9.4, 4, 5};
    double expected[] = {1, 2, 5};
    templated_array_copy(source, dest);
    for (int i = 0; i < 3; ++i) {
        cout << expected[i] << ": "<<  dest[i] << endl;
        // ASSERT_EQ(expected[i], dest[i]);
    }
} // t1

void test2(){
    int source[] = {1, 2};
    int dest[] = {9, 4, 5};
    int expected[] = {1, 2, 5};
    templated_array_copy(source, dest);
    for (int i = 0; i < 3; ++i) {
        cout << expected[i] << ": "<<  dest[i] << endl;
        //ASSERT_EQ(expected[i], dest[i]);
    }

} // t2

int main(){
    test2();
    return 0;
} // main