/*
Write a function (named "templated_array_copy") that takes two parameters 
(two arrays of the same type). It copies the first array into the second. 
Note, it the arrays are different sizes, only copy what fits.
*/
#include "mimir_testing.h"

template <typename T>
void templated_array_copy(T* source, T* dest){

} // temp_arr_copy


void test1(){
    double source[] = {1, 2, 5, 6};
    double dest[] = {9.4, 4, 5};
    double expected[] = {1, 2, 5};
    templated_array_copy(source, dest);
    for (int i = 0; i < 3; ++i) {
        ASSERT_EQ(expected[i], dest[i]);
    }
} // t1

void test2(){
    int source[] = {1, 2};
    int dest[] = {9, 4, 5};
    int expected[] = {1, 2, 5};
    templated_array_copy(source, dest);
    for (int i = 0; i < 3; ++i) {
        ASSERT_EQ(expected[i], dest[i]);
    }

} // t2

int main(){
    test1();
    test2();
    return 0;
} // main